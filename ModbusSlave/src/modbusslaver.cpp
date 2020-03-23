#include "modbusslaver.h"
#include "ui_modbusslaver.h"
#include <QHeaderView>
#include <QFileDialog>
//#include <QMenu>
//#include <QSpacerItem>
//#include <QAbstractSpinBox>
//#include <QDir>
//#include <QDesktopServices>

ModbusSlaver::ModbusSlaver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModbusSlaver)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    this->initComboBox_Config();
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler( QSerialPort::SerialPortError)));
    connect(this,SIGNAL(signal_writtenData(QByteArray)),currentPort,SLOT(slot_writtenData(QByteArray)));

    this->tableInit();
}

ModbusSlaver::~ModbusSlaver()
{
    delete ui;
}

/*   初始化了串口设置当中的下拉列表(ComboBox) */
void ModbusSlaver::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
}

/* 刷新按钮点击 槽函数 */
void ModbusSlaver::on_btnRefresh_clicked()
{
    if( !ui->btnOpenPort->isChecked()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* 打开串口 槽函数*/
void ModbusSlaver::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
            this->configPort();
            connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_RxCallback()));// 有数据就直接接收显示
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void ModbusSlaver::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}

/* 串口错误信息处理 */
void ModbusSlaver::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}

/*------------------------------ ui事件处理 --------------------------------------*/

void ModbusSlaver::tableInit()
{
    this->setLineEditInputType();
    this->setWindowTitle("ModbusTool-Slaver - ing10 v1.0");
    ui->txtMessage->setStyleSheet("background-color: rgb(46, 47, 48);"); // 信息窗口背景颜色
    ui->tblCoil->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );// 自适应列宽
    this->on_btnLoad_clicked(true); // 加载默认的数据
}

/**
 * @brief ModbusTool::setLineEditInputType 限制文本输入格式
 */
void ModbusSlaver::setLineEditInputType()
{
    QRegExp regExp("[0-9]{0,5}"); // 匹配数字
    QRegExpValidator *reg = new QRegExpValidator(regExp,this);
    ui->txtCoilNum->setValidator(reg);// 设定正则表达式
    ui->txtRegNum->setValidator(reg);

    regExp.setPattern( "[0-9a-f]{0,4}" );
    regExp.setCaseSensitivity(Qt::CaseInsensitive);
    QRegExpValidator *reg1 = new QRegExpValidator(regExp,this);
    ui->txtCoilStartAddr->setValidator(reg1);
    ui->txtRegStartAddr->setValidator(reg1);

}

/**
 * @brief ModbusSlaver::setStartAddr 设置表头起始地址
 * @param startAddr
 */
void ModbusSlaver::setCoilStartAddr(quint16 startAddr)
{
    quint32 rows = startAddr + ui->tblCoil->rowCount();
    QStringList vHeaderLabel;
    for(quint32 i=startAddr; i<rows; i++){
        QString tmp1 = QString("%1").arg(i, 4, 16, QLatin1Char('0'));
        vHeaderLabel<<tmp1.toUpper() ;
    }
    ui->tblCoil->setVerticalHeaderLabels( vHeaderLabel );
}

/**
 * @brief ModbusSlaver::on_txtCoilStartAddr_editingFinished 设置Coil的起始地址
 */
void ModbusSlaver::on_txtCoilStartAddr_editingFinished()
{
    quint16 startAddr = ui->txtCoilStartAddr->text().toInt(nullptr,16);
    this->setCoilStartAddr(startAddr);
}
/**
 * @brief ModbusSlaver::on_ckbCoilHideAlias_clicked 隐藏线圈别名
 * @param checked
 */
void ModbusSlaver::on_ckbCoilHideAlias_clicked(bool checked)
{
    if(checked){
        ui->tblCoil->hideColumn(0);
    }else
        ui->tblCoil->showColumn(0);
}
/**
 * @brief ModbusSlaver::on_ckbCoilHideAddr_clicked 隐藏线圈地址
 * @param checked
 */
void ModbusSlaver::on_ckbCoilHideAddr_clicked(bool checked)
{
    if(checked){
        ui->tblCoil->verticalHeader()->setVisible(false);
    }else{
        ui->tblCoil->verticalHeader()->setVisible(true);
    }
}
/**
 * @brief ModbusSlaver::on_txtCoilNum_editingFinished 修改Coil总数量
 */
void ModbusSlaver::on_txtCoilNum_editingFinished()
{
    quint32 startAddr = ui->tblCoil->verticalHeaderItem(0)->text().toInt(nullptr,16);
    quint32 newCoilsNum = ui->txtCoilNum->text().toInt();
    if(newCoilsNum==0){
        quint32 CurrentCoilsNum = ui->tblCoil->rowCount();
        ui->txtRegNum->setText( QString("%1").arg(CurrentCoilsNum));
        return;
    }
    if( (newCoilsNum + startAddr)>65536 ){
        newCoilsNum = 65536 - startAddr;
    }
    disconnect(ui->tblCoil,SIGNAL(cellChanged(int,int)),this,SLOT(on_tblCoil_cellChanged(int,int)));

    ui->tblCoil->setRowCount(newCoilsNum);
    this->setCoilStartAddr(startAddr);
    ui->txtCoilNum->setText( QString("%1").arg(newCoilsNum));
    this->setCoilInit();

    connect(ui->tblCoil,SIGNAL(cellChanged(int,int)),this,SLOT(on_tblCoil_cellChanged(int,int)));
}

/**
 * @brief ModbusSlaver::setCoilInit 线圈初始化
 */
void ModbusSlaver::setCoilInit()
{
    qint32 coilsNum = ui->tblCoil->rowCount();

    for(qint32 i=0; i<coilsNum; i++ ) {
        QTableWidgetItem *item = ui->tblCoil->item(i, 1);
        if( item == NULL ){
            item = new QTableWidgetItem();
            item->setCheckState(Qt::Unchecked );
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText("OFF");
            ui->tblCoil->setItem(i,1,item);
        }
    }

}

/**
 * @brief ModbusSlaver::on_tblCoil_cellChanged 单元格内容发生改变
 * @param row
 * @param column
 */
void ModbusSlaver::on_tblCoil_cellChanged(int row, int column)
{
    if(column != 1) return ;
    QTableWidgetItem *item = ui->tblCoil->item(row, column);
    if(item != NULL){
        disconnect(ui->tblCoil,SIGNAL(cellChanged(int,int)),this,SLOT(on_tblCoil_cellChanged(int,int)));
        if(item->checkState() == Qt::Checked){
            item->setText("ON");
            item->setBackgroundColor(QColor(127, 127, 127));
        }else{
            item->setText("OFF");
            item->setBackgroundColor(QColor(255, 255, 255));
        }
        connect(ui->tblCoil,SIGNAL(cellChanged(int,int)),this,SLOT(on_tblCoil_cellChanged(int,int)));
    }
}

/**
 * @brief ModbusSlaver::setRegStartAddr  设置寄存器的起始地址
 * @param startAddr
 */
void ModbusSlaver::setRegStartAddr(quint16 startAddr)
{
    quint32 rows = startAddr + ui->tblReg->rowCount();
    QStringList vHeaderLabel;

    for(quint32 i=startAddr; i<rows; i++){
        QString tmp1 = QString("%1").arg(i, 4, 16, QLatin1Char('0'));
        vHeaderLabel<<tmp1.toUpper() ;
    }
    ui->tblReg->setVerticalHeaderLabels( vHeaderLabel );
}
/**
 * @brief ModbusSlaver::on_ckbRegHideAlias_clicked 隐藏寄存器别名
 * @param checked
 */
void ModbusSlaver::on_ckbRegHideAlias_clicked(bool checked)
{
    if(checked){
        ui->tblReg->hideColumn(0);
    }else
        ui->tblReg->showColumn(0);
}
/**
 * @brief ModbusSlaver::on_ckbRegHideAddr_clicked 隐藏地址
 * @param checked
 */
void ModbusSlaver::on_ckbRegHideAddr_clicked(bool checked)
{
    if(checked){
        ui->tblReg->verticalHeader()->setVisible(false);
    }else{
        ui->tblReg->verticalHeader()->setVisible(true);
    }
}

/**
 * @brief ModbusSlaver::on_txtRegStartAddr_editingFinished 设置寄存器起始地址
 */
void ModbusSlaver::on_txtRegStartAddr_editingFinished()
{
    quint16 startAddr = ui->txtRegStartAddr->text().toInt(nullptr,16);
    this->setRegStartAddr(startAddr);
}
/**
 * @brief ModbusSlaver::on_txtRegNum_editingFinished 设置寄存器总数量
 */
void ModbusSlaver::on_txtRegNum_editingFinished()
{
    quint32 startAddr = ui->tblReg->verticalHeaderItem(0)->text().toInt(nullptr,16);
    quint32 newRegsNum = ui->txtRegNum->text().toInt();
    if(newRegsNum==0){
        quint32 CurrentRegsNum = ui->tblReg->rowCount();
        ui->txtRegNum->setText( QString("%1").arg(CurrentRegsNum));
        return;
    }
    if( (newRegsNum + startAddr)>65536 ){
        newRegsNum = 65536 - startAddr;
    }
    ui->tblReg->setRowCount(newRegsNum);
    this->setRegStartAddr(startAddr);
    ui->txtRegNum->setText( QString("%1").arg(newRegsNum));
    this->setRegInit();
}
/**
 * @brief ModbusSlaver::setRegInit 寄存器初始化
 */
void ModbusSlaver::setRegInit()
{
    qint32 RegsNum = ui->tblReg->rowCount();

    for(qint32 i=0; i<RegsNum; i++ ) {
        QTableWidgetItem *item = ui->tblReg->item(i, 1);
        if( item == NULL ){
            item = new QTableWidgetItem();
            ui->tblReg->setItem(i,1,item);
            item->setText("0000");
        }
    }
}



///*-------------------------  接收数据帧处理 -------------------------*/

/**
 * @brief ModbusTool::slots_RxCallback 串口接收数据,存储在dataBuf当中
 */
void ModbusSlaver::slots_RxCallback()
{
    /*-------- 设置文本颜色 ----------*/
    ui->txtMessage->setTextColor(QColor(102, 163, 52));
    QByteArray tmp = currentPort->readAll();
    rxDataBuf.append(tmp);
    this->insertLogAtTime("Rx: " + rxDataBuf.toHex(' ').toUpper());
    rxDataBuf.clear();

}
/**
 * @brief ModbusTool::insertLog 在信息框插入信息
 * @param msg
 */
void ModbusSlaver::insertLogAtTime(QString msg)
{
    /* 数据显示 */
    QTime currentTime = QTime::currentTime();
    QString txt = currentTime.toString("[hh:mm:ss.zzz]");
    ui->txtMessage->append( msg.prepend(txt.toLocal8Bit()));
}
/**
 * @brief ModbusTool::sendFrame 发送数据帧
 * @param txbuf 待发送的数据（不含校验码）
 */
void ModbusSlaver::sendFrame(QByteArray txbuf)
{
    /*-------- 设置文本颜色 ----------*/
    ui->txtMessage->setTextColor(QColor(255, 128, 128));

    /* RTU模式 */
    if( ui->rdbRTU->isChecked() ){
        if( ui->ckbInsertCRC->isChecked() ){
            quint16 CRC = crc16_modbus_calc((quint8*)txbuf.data(), txbuf.size());
            txbuf.append(CRC);
            txbuf.append(CRC>>8);
        }
        emit signal_writtenData(txbuf);
        this->insertLogAtTime("Tx: " + txbuf.toHex(' ').toUpper());

    }else{/* ASCII模式 */
        if( ui->ckbInsertCRC->isChecked() ){
            quint8 LRC = verifyLRC((quint8*)txbuf.data(), txbuf.size());
            txbuf.append(LRC);
        }
        QByteArray tmp = txbuf.toHex().toUpper().prepend(":");
        tmp.append("\r\n"); // 0x0D 0x0A
        emit signal_writtenData(tmp);
        tmp.replace("\r\n","\\r\\n");
        this->insertLogAtTime("Tx: " + tmp);
    }
}



/*************************
 * Name:    CRC-16/MODBUS x16+x15+x2+1
 * Poly:    0x8005
 * Init:    0xFFFF
 * Refin:   True
 * Refout:  True
 * Xorout:  0x0000
 * Note:
*************************/
static quint16 crc16Modbus_table[256] = {
0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241, 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640, 0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41, 0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640, 0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40, 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040,
};

quint16 ModbusSlaver::crc16_modbus_calc(quint8 *data, quint32 length)
{
    uint16_t tmp = 0;
    uint16_t crc = 0xFFFF;                // Initial value
    while(length--)
    {
        tmp =  (0x00FF & crc) ^ (*data++);    // crc ^= *data; data++;
        crc = (crc >> 8) ^ crc16Modbus_table[tmp&0xFF];
    }
    return crc; // crc
}

/**
 * @brief ModbusTool::verifyLRC  LRC校验码
 * @param data     数据缓存
 * @param length   缓存长度
 * @return  lrc    LRC校验码
 */
quint8 ModbusSlaver::verifyLRC(quint8 *data, quint32 length)
{
    if(length == 0) return 0;
    quint8 lrc = 0;
    while(length--){
        lrc += *data++;
    }
    lrc = (~lrc) + 1;
    return lrc;
}

/*-------------------------------- 数据保存与读取 -----------------------------------------*/

/**
 * @brief ModbusSlaver::on_btnSave_clicked 保存Coil和Reg表格
 */
void ModbusSlaver::on_btnSave_clicked(bool getDefault)
{
    QSettings *settings;
    if(getDefault){
        settings = new QSettings("default.ini", QSettings::IniFormat);
    }else{
        QString filePath = QFileDialog::getSaveFileName(this,"保存",qApp->applicationDirPath(),"*.ini");
        settings = new QSettings(filePath, QSettings::IniFormat);
    }

    settings->setIniCodec("GBK"); // 设置编码器,支持中文读写

    quint32 coilNums = ui->tblCoil->rowCount();
    settings->beginGroup("GlobalConfig");
    settings->setValue( "SlaverAddr",  ui->txtAddr->text() );   // 起始地址
    settings->setValue( "RTUMode",  ui->rdbRTU->isChecked() ); // 通信模式
    settings->setValue( "ASCIIMode",  ui->rdbASCII->isChecked() ); // 通信模式
    settings->endGroup();

    settings->beginGroup("coilTable");
    settings->setValue( "StartAddr",  ui->tblCoil->verticalHeaderItem(0)->text() ); // 起始地址
    settings->setValue( "HideAlias",  ui->ckbCoilHideAlias->checkState() ); // 隐藏别名
    settings->setValue( "HideAddr",   ui->ckbCoilHideAddr->checkState() ); // 隐藏别名

    /* 以数组格式存储表格项 */
    settings->beginWriteArray("Coil");

    for(quint32 i=0; i<coilNums; i++){
        settings->setArrayIndex(i);

        if(ui->tblCoil->item(i,0) == NULL ){
            settings->setValue( "Alias",  "NULL" ); // 记录别名
        }else{
            if(ui->tblCoil->item(i,0)->text() != NULL)
                settings->setValue( "Alias",  ui->tblCoil->item(i,0)->text() ); // 记录别名
            else settings->setValue( "Alias",  "NULL" ); // 记录别名
        }
        settings->setValue( "Checked",  ui->tblCoil->item(i,1)->checkState() ); // 记录coils状态
    }
    settings->endArray();
    settings->endGroup();

    /* 保存寄存器列表 */
    quint32 regNums = ui->tblReg->rowCount();
    settings->beginGroup("regTable");
    settings->setValue( "StartAddr",  ui->tblReg->verticalHeaderItem(0)->text() ); // 起始地址
    settings->setValue( "HideAlias",  ui->ckbRegHideAlias->checkState() ); // 隐藏别名
    settings->setValue( "HideAddr",   ui->ckbRegHideAddr->checkState() ); // 隐藏别名

    settings->beginWriteArray("Register");

    for(quint32 i=0; i<regNums; i++){
        settings->setArrayIndex(i);

        if(ui->tblReg->item(i,0) == NULL ){
            settings->setValue( "Alias",  "NULL" ); // 记录别名
        }else{
            if(ui->tblReg->item(i,0)->text() != NULL)
                settings->setValue( "Alias",  ui->tblReg->item(i,0)->text() ); // 记录别名
            else settings->setValue( "Alias",  "NULL" ); // 记录别名
        }
        settings->setValue( "Value",  ui->tblReg->item(i,1)->text() ); // 记录Regs状态
    }
    settings->endArray();
    settings->endGroup();
}
/**
 * @brief ModbusSlaver::on_btnLoad_clicked 加载数据
 */
void ModbusSlaver::on_btnLoad_clicked(bool getDefault)
{
    QSettings *settings;
    if(getDefault){
        settings = new QSettings("default.ini", QSettings::IniFormat);

    }else{
        QString filePath = QFileDialog::getOpenFileName(this,"加载",qApp->applicationDirPath(),"*.ini");
        settings = new QSettings(filePath, QSettings::IniFormat);
    }
    settings->setIniCodec("GBK"); // 设置编码器,支持中文读写

    settings->beginGroup("GlobalConfig");
    ui->txtAddr->setText( settings->value( "SlaverAddr").toString());   // 起始地址
    ui->rdbRTU->setChecked( settings->value( "RTUMode" ).toBool());     // 通信模式
    ui->rdbASCII ->setChecked( settings->value( "ASCIIMode" ).toBool()); // 通信模式
    settings->endGroup();

    settings->beginGroup("coilTable");

    /* 起始地址 */
//    quint16 startCoilAddr = settings->value("startAddr").toInt();
    QString tmp1 = settings->value("startAddr").toString();
    ui->txtCoilStartAddr->setText( tmp1 );
    this->setCoilStartAddr( tmp1.toInt(nullptr, 16) );

    /* 线圈数量 */
    quint32 coilNums = settings->beginReadArray("Coil");
    ui->txtCoilNum->setText( QString::number(coilNums) );
    ui->txtCoilNum->editingFinished();


    /* 隐藏行,列 */
    Qt::CheckState hideCoilAddr = (Qt::CheckState)settings->value( "HideAlias" ).toInt();
    Qt::CheckState hideCoilAlias = (Qt::CheckState)settings->value( "HideAlias" ).toInt();
    ui->ckbCoilHideAddr->setChecked( hideCoilAddr );
    ui->ckbCoilHideAlias->setChecked( hideCoilAlias );

    /* 读取别名的线圈状态 */
    for(quint32 i=0; i<coilNums; i++ ){
        settings->setArrayIndex(i);
        QString alias = settings->value("Alias").toString();
        if( !alias.operator ==("NULL") ){
            if( ui->tblCoil->item(i, 0) == NULL ){
                QTableWidgetItem *item = new QTableWidgetItem();
                ui->tblCoil->setItem(i, 0, item);
            }
            ui->tblCoil->item(i, 0)->setText(alias);
        }
        Qt::CheckState checked = (Qt::CheckState)settings->value( "Checked" ).toInt();
        ui->tblCoil->item(i,1)->setCheckState(checked);
    }

    settings->endArray();
    settings->endGroup();

    /* 寄存器表格 */
    settings->beginGroup("regTable");

    QString tmp2 = settings->value("startAddr").toString();
    ui->txtRegStartAddr->setText( tmp2 );
    this->setRegStartAddr(tmp2.toInt(nullptr, 16));

    quint32 regNums = settings->beginReadArray("Register");
    ui->txtRegNum->setText( QString::number(regNums) );
    ui->txtRegNum->editingFinished();

    Qt::CheckState hideRegAddr = (Qt::CheckState)settings->value( "HideAlias" ).toInt();
    Qt::CheckState hideRegAlias = (Qt::CheckState)settings->value( "HideAlias" ).toInt();
    ui->ckbRegHideAddr->setChecked( hideRegAddr );
    ui->ckbRegHideAlias->setChecked( hideRegAlias );

    for(quint32 i=0; i<regNums; i++ ){
        settings->setArrayIndex(i);
        QString alias = settings->value("Alias").toString();
        if( !alias.operator ==("NULL") ){
            if( ui->tblReg->item(i, 0) == NULL ){
                QTableWidgetItem *item = new QTableWidgetItem();
                ui->tblReg->setItem(i, 0, item);
            }
            ui->tblReg->item(i, 0)->setText(alias);
        }
        QString value = settings->value( "Value" ).toString();
        ui->tblReg->item(i,1)->setText(value);
    }

    settings->endArray();
    settings->endGroup();
}
/**
 * @brief ModbusTool::closeEvent 重写窗口关闭事件，保存数据
 * @param e
 */
void ModbusSlaver::closeEvent(QCloseEvent *e)
{
    e = e;
    this->on_btnSave_clicked(true);
}

