#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTime>
#include <QTimer>
#include <QSettings>
#include <QCloseEvent>
#include <QScrollArea>
#include <QSpinBox>
#include <QTableWidgetItem>


namespace Ui {
class ModbusSlaver;
}

class ModbusSlaver : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusSlaver(QWidget *parent = 0);
    ~ModbusSlaver();

    /* 接收数据帧 */
    struct RxProtocal{
        quint8 slaveAddr; // 从设备地址
        quint8 cmd;       // 指令
        quint16 regAddr;  // 寄存器地址
        quint16 regNum;   // 寄存器数量
        quint8  byteNum;  // 字节数
        quint8  data[256];// 数据
        quint16  verify; // 校验码
    }rxFrame;

    enum ProtocalMode{
        RTU,
        ASCII,
    };
    enum ModbusCMD{
        cmd01H = 0x01,
        cmd02H = 0x02,
        cmd03H = 0x03,
        cmd04H = 0x04,
        cmd05H = 0x05,
        cmd06H = 0x06,
        cmd0FH = 0x0F,
        cmd10H = 0x10,
    };
    enum ExceptionCode{
        Exception01 = 1,
        Exception02 ,
        Exception03 ,
        Exception04 ,
        Exception05 ,
        Exception06 ,
        Exception07 ,
        Exception08 ,
    };



    QByteArray rxDataBuf;
    int   Count = 0;
    QTime *rxTime;

    void initComboBox_Config();
    void configPort();
    void initPlot();
    void setLineEditInputType();

    quint16 crc16_modbus_calc(quint8 *data, quint32 length);
    quint8 verifyLRC(quint8 *data, quint32 length);
    void sendFrame(QByteArray txbuf);
    void insertLogAtTime(QString msg);


    void tableInit();

    void setCoilStartAddr(quint16 startAddr);
    void setRegStartAddr(quint16 startAddr);

    void setCoilInit();
    void setRegInit();


    bool handleRTUProtocal();
    bool handleASCIIProtocal();
    bool checkVerify( QByteArray &rxbuf,quint16 &verify, ProtocalMode mode);
    void handleReadRegister(ProtocalMode mode);
    void handleWriteRegister( ProtocalMode mode, bool multiReg);

    void handleReadCoil(ProtocalMode mode);
    void handleWriteCoil(  ProtocalMode mode, bool multiCoil );
//    void handleWriteRegister( ProtocalMode mode, bool multiReg);


//    void exceptionHandle(ExceptionCode exception );

signals:
    void signal_writtenData(QByteArray txBuf);

    void signal_cmd01HProtocal(ProtocalMode);

    void signal_cmd03HProtocal(ProtocalMode);

    void signal_cmd05HProtocal(ProtocalMode);

    void signal_cmd06HProtocal(ProtocalMode);

    void signal_cmd0FHProtocal(ProtocalMode);

    void signal_cmd10HProtocal(ProtocalMode);

    void signal_exceptionHandle(ModbusCMD cmd,ExceptionCode exception);


public slots :
    void slots_RxCallback();

    void slots_errorHandler(QSerialPort::SerialPortError error);

    void  slots_rxTimeout();

    void slots_cmd01HProtocal(ProtocalMode);

    void slots_cmd03HProtocal(ProtocalMode);

    void slots_cmd05HProtocal(ProtocalMode);

    void slots_cmd06HProtocal(ProtocalMode);

    void slots_cmd0FHProtocal(ProtocalMode);

    void slots_cmd10HProtocal(ProtocalMode);

    void slots_exceptionHandle(ModbusCMD cmd,ExceptionCode exception);


private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked(bool checked);

    void on_txtCoilStartAddr_editingFinished();

    void on_ckbCoilHideAlias_clicked(bool checked);

    void on_ckbCoilHideAddr_clicked(bool checked);

    void on_txtCoilNum_editingFinished();

//    void on_spbCoilRows_editingFinished();

    void on_ckbRegHideAlias_clicked(bool checked);

    void on_ckbRegHideAddr_clicked(bool checked);

    void on_txtRegStartAddr_editingFinished();

    void on_txtRegNum_editingFinished();

    void on_tblCoil_cellChanged(int row, int column);

    void on_btnSave_clicked(bool getDefault = false);

    void on_btnLoad_clicked(bool getDefault = false);


    void on_actionModbusPro_triggered();

    void on_toolButton_clicked();

    void on_actionStyle_triggered();

protected :
    void closeEvent(QCloseEvent *event);

private:
    Ui::ModbusSlaver *ui;
    BaseSerialComm *currentPort;   // 端口号

};

#endif // MODBUSTOOL_H

