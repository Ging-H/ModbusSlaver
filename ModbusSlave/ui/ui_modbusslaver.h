/********************************************************************************
** Form generated from reading UI file 'modbusslaver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSSLAVER_H
#define UI_MODBUSSLAVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusSlaver
{
public:
    QAction *actionModbusPro;
    QAction *actionHelp;
    QAction *actionRename;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QPushButton *btnRefresh;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblPortNum;
    QComboBox *cbbPortNum;
    QLabel *lblBaudRate;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QComboBox *cbbDataBit;
    QLabel *lblVerify;
    QComboBox *cbbVerify;
    QLabel *lblStopBit;
    QComboBox *cbbStopBit;
    QTextEdit *txtMessage;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_2;
    QCheckBox *ckbInsertCRC;
    QToolButton *toolButton;
    QSplitter *splitter_2;
    QRadioButton *rdbRTU;
    QRadioButton *rdbASCII;
    QFrame *line;
    QRadioButton *radioButton;
    QToolBar *toolBar;
    QButtonGroup *bgpMSS;

    void setupUi(QMainWindow *ModbusSlaver)
    {
        if (ModbusSlaver->objectName().isEmpty())
            ModbusSlaver->setObjectName(QStringLiteral("ModbusSlaver"));
        ModbusSlaver->resize(793, 630);
        ModbusSlaver->setMinimumSize(QSize(0, 0));
        actionModbusPro = new QAction(ModbusSlaver);
        actionModbusPro->setObjectName(QStringLiteral("actionModbusPro"));
        actionHelp = new QAction(ModbusSlaver);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionRename = new QAction(ModbusSlaver);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        centralWidget = new QWidget(ModbusSlaver);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        QGBSerialConfig = new QGroupBox(centralWidget);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy);
        QGBSerialConfig->setMinimumSize(QSize(171, 221));
        QGBSerialConfig->setMaximumSize(QSize(171, 16777215));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        btnOpenPort->setGeometry(QRect(69, 165, 91, 31));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/action/action/centrejust.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/action/action/process-stop.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon);
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);
        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 165, 51, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon1);
        layoutWidget = new QWidget(QGBSerialConfig);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 146, 136));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblPortNum = new QLabel(layoutWidget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout->addWidget(lblPortNum, 0, 0, 1, 1);

        cbbPortNum = new QComboBox(layoutWidget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy1);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout->addWidget(cbbPortNum, 0, 1, 1, 1);

        lblBaudRate = new QLabel(layoutWidget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbBaud = new QComboBox(layoutWidget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(layoutWidget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout->addWidget(lblDataBit, 2, 0, 1, 1);

        cbbDataBit = new QComboBox(layoutWidget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblVerify = new QLabel(layoutWidget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout->addWidget(lblVerify, 3, 0, 1, 1);

        cbbVerify = new QComboBox(layoutWidget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbVerify, 3, 1, 1, 1);

        lblStopBit = new QLabel(layoutWidget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout->addWidget(lblStopBit, 4, 0, 1, 1);

        cbbStopBit = new QComboBox(layoutWidget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbStopBit, 4, 1, 1, 1);


        gridLayout_2->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        txtMessage = new QTextEdit(centralWidget);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        txtMessage->setReadOnly(true);

        gridLayout_2->addWidget(txtMessage, 2, 1, 1, 1);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(235, 0));
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        tableWidget_2 = new QTableWidget(splitter);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        if (tableWidget_2->rowCount() < 7)
            tableWidget_2->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(6, __qtablewidgetitem19);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(235, 0));
        splitter->addWidget(tableWidget_2);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_2->addWidget(splitter, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(0, 121));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        ckbInsertCRC = new QCheckBox(groupBox_2);
        ckbInsertCRC->setObjectName(QStringLiteral("ckbInsertCRC"));
        ckbInsertCRC->setGeometry(QRect(10, 30, 141, 18));
        ckbInsertCRC->setChecked(true);
        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 80, 61, 26));
        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(15, 55, 131, 18));
        splitter_2->setOrientation(Qt::Horizontal);
        rdbRTU = new QRadioButton(splitter_2);
        bgpMSS = new QButtonGroup(ModbusSlaver);
        bgpMSS->setObjectName(QStringLiteral("bgpMSS"));
        bgpMSS->addButton(rdbRTU);
        rdbRTU->setObjectName(QStringLiteral("rdbRTU"));
        rdbRTU->setChecked(true);
        splitter_2->addWidget(rdbRTU);
        rdbASCII = new QRadioButton(splitter_2);
        bgpMSS->addButton(rdbASCII);
        rdbASCII->setObjectName(QStringLiteral("rdbASCII"));
        splitter_2->addWidget(rdbASCII);
        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 115, 151, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(15, 130, 91, 18));

        gridLayout_2->addWidget(groupBox_2, 1, 0, 2, 1);

        ModbusSlaver->setCentralWidget(centralWidget);
        toolBar = new QToolBar(ModbusSlaver);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ModbusSlaver->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(cbbPortNum, cbbBaud);
        QWidget::setTabOrder(cbbBaud, cbbDataBit);
        QWidget::setTabOrder(cbbDataBit, cbbVerify);
        QWidget::setTabOrder(cbbVerify, cbbStopBit);
        QWidget::setTabOrder(cbbStopBit, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnOpenPort);
        QWidget::setTabOrder(btnOpenPort, ckbInsertCRC);
        QWidget::setTabOrder(ckbInsertCRC, rdbRTU);
        QWidget::setTabOrder(rdbRTU, rdbASCII);

        toolBar->addAction(actionHelp);
        toolBar->addAction(actionModbusPro);

        retranslateUi(ModbusSlaver);

        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(ModbusSlaver);
    } // setupUi

    void retranslateUi(QMainWindow *ModbusSlaver)
    {
        ModbusSlaver->setWindowTitle(QApplication::translate("ModbusSlaver", "ModbusTool", Q_NULLPTR));
        actionModbusPro->setText(QApplication::translate("ModbusSlaver", "Modbus\345\215\217\350\256\256", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("ModbusSlaver", "\345\270\256\345\212\251\350\257\264\346\230\216", Q_NULLPTR));
        actionRename->setText(QApplication::translate("ModbusSlaver", "\351\207\215\345\221\275\345\220\215", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("ModbusSlaver", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("ModbusSlaver", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("ModbusSlaver", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("ModbusSlaver", "\345\210\267\346\226\260", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("ModbusSlaver", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("ModbusSlaver", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("ModbusSlaver", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("ModbusSlaver", "\346\240\241\351\252\214", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("ModbusSlaver", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ModbusSlaver", "\345\210\253\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ModbusSlaver", "\345\200\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ModbusSlaver", "0000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("ModbusSlaver", "234234", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("ModbusSlaver", "\345\210\253\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("ModbusSlaver", "\345\200\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("ModbusSlaver", "0000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->verticalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("ModbusSlaver", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ModbusSlaver", "Config", Q_NULLPTR));
        ckbInsertCRC->setText(QApplication::translate("ModbusSlaver", "\350\207\252\345\212\250\346\267\273\345\212\240\346\240\241\351\252\214\347\240\201", Q_NULLPTR));
        toolButton->setText(QApplication::translate("ModbusSlaver", "\346\270\205\347\251\272", Q_NULLPTR));
        rdbRTU->setText(QApplication::translate("ModbusSlaver", "RTU", Q_NULLPTR));
        rdbASCII->setText(QApplication::translate("ModbusSlaver", "ASCII", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ModbusSlaver", "\351\232\220\350\227\217\345\210\253\345\220\215\345\210\227", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("ModbusSlaver", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusSlaver: public Ui_ModbusSlaver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSSLAVER_H
