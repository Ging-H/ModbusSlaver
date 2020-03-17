#ifndef MODBUSTOOL_H
#define MODBUSTOOL_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTime>
#include <QDebug>
#include <QTimer>
#include <QSettings>
#include <QCloseEvent>
#include <QScrollArea>
#include <QSpinBox>

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

    void initComboBox_Config();
    void configPort();
    void initPlot();
    void setLineEditInputType();

    quint16 crc16_modbus_calc(quint8 *data, quint32 length);
    quint8 verifyLRC(quint8 *data, quint32 length);
    void sendFrame(QByteArray txbuf);
    void insertLogAtTime(QString msg);
    void getInitTxt();


signals:
    void signal_writtenData(QByteArray txBuf);


public slots :
    void slots_RxCallback();

    void slots_errorHandler(QSerialPort::SerialPortError error);



private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked(bool checked);

protected :
    void closeEvent(QCloseEvent *event);

private:
    Ui::ModbusSlaver *ui;
    BaseSerialComm *currentPort;   // 端口号

};

#endif // MODBUSTOOL_H

