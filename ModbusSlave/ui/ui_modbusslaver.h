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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusSlaver
{
public:
    QAction *actionModbusPro;
    QAction *actionHelp;
    QAction *actionHex;
    QAction *actionDecimal;
    QAction *action_AB_CD;
    QAction *action_CD_AB;
    QAction *actionStyle;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_5;
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
    QPushButton *btnRefresh;
    QPushButton *btnOpenPort;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QTableWidget *tblCoil;
    QTableWidget *tblReg;
    QTextEdit *txtMessage;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *ckbInsertCRC;
    QSplitter *splitter_2;
    QRadioButton *rdbRTU;
    QRadioButton *rdbASCII;
    QLineEdit *txtAddr;
    QToolButton *toolButton;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QToolBox *toolBox;
    QWidget *page;
    QLineEdit *txtCoilNum;
    QCheckBox *ckbCoilHideAddr;
    QLineEdit *txtCoilStartAddr;
    QCheckBox *ckbCoilHideAlias;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QCheckBox *ckbRegHideAlias;
    QCheckBox *ckbRegHideAddr;
    QLineEdit *txtRegStartAddr;
    QLineEdit *txtRegNum;
    QToolBar *toolBar;
    QButtonGroup *bgpMSS;

    void setupUi(QMainWindow *ModbusSlaver)
    {
        if (ModbusSlaver->objectName().isEmpty())
            ModbusSlaver->setObjectName(QStringLiteral("ModbusSlaver"));
        ModbusSlaver->resize(669, 503);
        ModbusSlaver->setMinimumSize(QSize(0, 0));
        actionModbusPro = new QAction(ModbusSlaver);
        actionModbusPro->setObjectName(QStringLiteral("actionModbusPro"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/general/general/protocol.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModbusPro->setIcon(icon);
        actionHelp = new QAction(ModbusSlaver);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHex = new QAction(ModbusSlaver);
        actionHex->setObjectName(QStringLiteral("actionHex"));
        actionDecimal = new QAction(ModbusSlaver);
        actionDecimal->setObjectName(QStringLiteral("actionDecimal"));
        action_AB_CD = new QAction(ModbusSlaver);
        action_AB_CD->setObjectName(QStringLiteral("action_AB_CD"));
        action_CD_AB = new QAction(ModbusSlaver);
        action_CD_AB->setObjectName(QStringLiteral("action_CD_AB"));
        actionStyle = new QAction(ModbusSlaver);
        actionStyle->setObjectName(QStringLiteral("actionStyle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/general/general/Style.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStyle->setIcon(icon1);
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
        QGBSerialConfig->setMinimumSize(QSize(171, 205));
        QGBSerialConfig->setMaximumSize(QSize(171, 16777215));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        gridLayout_5 = new QGridLayout(QGBSerialConfig);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout->addWidget(lblPortNum, 0, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
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

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout->addWidget(lblDataBit, 2, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout->addWidget(lblVerify, 3, 0, 1, 1);

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbVerify, 3, 1, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout->addWidget(lblStopBit, 4, 0, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(cbbStopBit, 4, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 2);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        sizePolicy1.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy1);
        btnRefresh->setMaximumSize(QSize(60, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/action/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);
        btnRefresh->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(btnRefresh, 1, 0, 1, 1);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnOpenPort->sizePolicy().hasHeightForWidth());
        btnOpenPort->setSizePolicy(sizePolicy1);
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/general/general/com_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/general/general/com_connect_1.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon3);
        btnOpenPort->setIconSize(QSize(32, 32));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_5->addWidget(btnOpenPort, 1, 1, 1, 1);


        gridLayout_2->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setLineWidth(2);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(4);
        splitter->setChildrenCollapsible(true);
        tblCoil = new QTableWidget(splitter);
        if (tblCoil->columnCount() < 2)
            tblCoil->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCoil->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCoil->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tblCoil->rowCount() < 10)
            tblCoil->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblCoil->setVerticalHeaderItem(9, __qtablewidgetitem11);
        tblCoil->setObjectName(QStringLiteral("tblCoil"));
        tblCoil->setMinimumSize(QSize(235, 0));
        tblCoil->setGridStyle(Qt::DashDotLine);
        tblCoil->setSortingEnabled(false);
        tblCoil->setWordWrap(false);
        tblCoil->setCornerButtonEnabled(false);
        splitter->addWidget(tblCoil);
        tblReg = new QTableWidget(splitter);
        if (tblReg->columnCount() < 2)
            tblReg->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblReg->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblReg->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        if (tblReg->rowCount() < 10)
            tblReg->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(6, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(7, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(8, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblReg->setVerticalHeaderItem(9, __qtablewidgetitem23);
        tblReg->setObjectName(QStringLiteral("tblReg"));
        tblReg->setMinimumSize(QSize(235, 0));
        tblReg->setGridStyle(Qt::DashDotLine);
        splitter->addWidget(tblReg);
        tblReg->verticalHeader()->setDefaultSectionSize(25);
        splitter_3->addWidget(splitter);
        txtMessage = new QTextEdit(splitter_3);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        txtMessage->setReadOnly(true);
        splitter_3->addWidget(txtMessage);

        gridLayout_2->addWidget(splitter_3, 0, 1, 3, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(0, 121));
        groupBox_2->setMaximumSize(QSize(171, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        ckbInsertCRC = new QCheckBox(groupBox_2);
        ckbInsertCRC->setObjectName(QStringLiteral("ckbInsertCRC"));
        ckbInsertCRC->setChecked(true);

        gridLayout_3->addWidget(ckbInsertCRC, 0, 0, 1, 3);

        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(0);
        rdbRTU = new QRadioButton(splitter_2);
        bgpMSS = new QButtonGroup(ModbusSlaver);
        bgpMSS->setObjectName(QStringLiteral("bgpMSS"));
        bgpMSS->addButton(rdbRTU);
        rdbRTU->setObjectName(QStringLiteral("rdbRTU"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(rdbRTU->sizePolicy().hasHeightForWidth());
        rdbRTU->setSizePolicy(sizePolicy4);
        rdbRTU->setChecked(true);
        splitter_2->addWidget(rdbRTU);
        rdbASCII = new QRadioButton(splitter_2);
        bgpMSS->addButton(rdbASCII);
        rdbASCII->setObjectName(QStringLiteral("rdbASCII"));
        sizePolicy4.setHeightForWidth(rdbASCII->sizePolicy().hasHeightForWidth());
        rdbASCII->setSizePolicy(sizePolicy4);
        splitter_2->addWidget(rdbASCII);

        gridLayout_3->addWidget(splitter_2, 1, 0, 1, 2);

        txtAddr = new QLineEdit(groupBox_2);
        txtAddr->setObjectName(QStringLiteral("txtAddr"));

        gridLayout_3->addWidget(txtAddr, 1, 2, 1, 1);

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/action/action/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(toolButton, 2, 0, 1, 1);

        btnSave = new QPushButton(groupBox_2);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/general/general/Save_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon5);
        btnSave->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(btnSave, 2, 1, 1, 1);

        btnLoad = new QPushButton(groupBox_2);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/general/general/edit_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoad->setIcon(icon6);
        btnLoad->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(btnLoad, 2, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy5);
        toolBox->setMinimumSize(QSize(171, 0));
        toolBox->setMaximumSize(QSize(171, 16777215));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 171, 68));
        txtCoilNum = new QLineEdit(page);
        txtCoilNum->setObjectName(QStringLiteral("txtCoilNum"));
        txtCoilNum->setGeometry(QRect(85, 45, 76, 20));
        ckbCoilHideAddr = new QCheckBox(page);
        ckbCoilHideAddr->setObjectName(QStringLiteral("ckbCoilHideAddr"));
        ckbCoilHideAddr->setGeometry(QRect(85, 10, 71, 18));
        txtCoilStartAddr = new QLineEdit(page);
        txtCoilStartAddr->setObjectName(QStringLiteral("txtCoilStartAddr"));
        txtCoilStartAddr->setGeometry(QRect(5, 45, 71, 20));
        ckbCoilHideAlias = new QCheckBox(page);
        ckbCoilHideAlias->setObjectName(QStringLiteral("ckbCoilHideAlias"));
        ckbCoilHideAlias->setGeometry(QRect(5, 10, 71, 18));
        toolBox->addItem(page, QStringLiteral("Coil"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 171, 68));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ckbRegHideAlias = new QCheckBox(page_2);
        ckbRegHideAlias->setObjectName(QStringLiteral("ckbRegHideAlias"));

        gridLayout_4->addWidget(ckbRegHideAlias, 0, 0, 1, 1);

        ckbRegHideAddr = new QCheckBox(page_2);
        ckbRegHideAddr->setObjectName(QStringLiteral("ckbRegHideAddr"));

        gridLayout_4->addWidget(ckbRegHideAddr, 0, 1, 1, 1);

        txtRegStartAddr = new QLineEdit(page_2);
        txtRegStartAddr->setObjectName(QStringLiteral("txtRegStartAddr"));

        gridLayout_4->addWidget(txtRegStartAddr, 1, 0, 1, 1);

        txtRegNum = new QLineEdit(page_2);
        txtRegNum->setObjectName(QStringLiteral("txtRegNum"));

        gridLayout_4->addWidget(txtRegNum, 1, 1, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Reg"));

        gridLayout_2->addWidget(toolBox, 2, 0, 1, 1);

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

        toolBar->addAction(actionModbusPro);
        toolBar->addAction(actionStyle);

        retranslateUi(ModbusSlaver);
        QObject::connect(toolButton, SIGNAL(clicked()), txtMessage, SLOT(clear()));

        btnOpenPort->setDefault(false);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModbusSlaver);
    } // setupUi

    void retranslateUi(QMainWindow *ModbusSlaver)
    {
        ModbusSlaver->setWindowTitle(QApplication::translate("ModbusSlaver", "ModbusTool", Q_NULLPTR));
        actionModbusPro->setText(QApplication::translate("ModbusSlaver", "Modbus\345\215\217\350\256\256", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("ModbusSlaver", "\345\270\256\345\212\251\350\257\264\346\230\216", Q_NULLPTR));
        actionHex->setText(QApplication::translate("ModbusSlaver", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR));
        actionDecimal->setText(QApplication::translate("ModbusSlaver", "\345\215\201\350\277\233\345\210\266", Q_NULLPTR));
        action_AB_CD->setText(QApplication::translate("ModbusSlaver", "\346\265\256\347\202\271\346\225\260 AB CD", Q_NULLPTR));
        action_CD_AB->setText(QApplication::translate("ModbusSlaver", "\346\265\256\347\202\271\346\225\260 CD AB", Q_NULLPTR));
        actionStyle->setText(QApplication::translate("ModbusSlaver", "Style", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("ModbusSlaver", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("ModbusSlaver", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("ModbusSlaver", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("ModbusSlaver", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("ModbusSlaver", "\346\240\241\351\252\214", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("ModbusSlaver", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("ModbusSlaver", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("ModbusSlaver", "\345\210\267\346\226\260", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("ModbusSlaver", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tblCoil->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ModbusSlaver", "\345\210\253\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tblCoil->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ModbusSlaver", "\347\272\277\345\234\210/\347\246\273\346\225\243\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tblCoil->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ModbusSlaver", "0000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tblCoil->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ModbusSlaver", "0001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tblCoil->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("ModbusSlaver", "0002", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tblCoil->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("ModbusSlaver", "0003", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tblCoil->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("ModbusSlaver", "0004", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tblCoil->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("ModbusSlaver", "0005", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tblCoil->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("ModbusSlaver", "0006", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tblCoil->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("ModbusSlaver", "0007", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tblCoil->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("ModbusSlaver", "0008", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tblCoil->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("ModbusSlaver", "0009", Q_NULLPTR));

        const bool __sortingEnabled = tblCoil->isSortingEnabled();
        tblCoil->setSortingEnabled(false);
        tblCoil->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem12 = tblReg->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("ModbusSlaver", "\345\210\253\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tblReg->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("ModbusSlaver", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tblReg->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("ModbusSlaver", "0000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tblReg->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("ModbusSlaver", "0001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tblReg->verticalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("ModbusSlaver", "0002", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tblReg->verticalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("ModbusSlaver", "0003", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tblReg->verticalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("ModbusSlaver", "0004", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tblReg->verticalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("ModbusSlaver", "0005", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tblReg->verticalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("ModbusSlaver", "0006", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tblReg->verticalHeaderItem(7);
        ___qtablewidgetitem21->setText(QApplication::translate("ModbusSlaver", "0007", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tblReg->verticalHeaderItem(8);
        ___qtablewidgetitem22->setText(QApplication::translate("ModbusSlaver", "0008", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tblReg->verticalHeaderItem(9);
        ___qtablewidgetitem23->setText(QApplication::translate("ModbusSlaver", "0009", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ModbusSlaver", "Config", Q_NULLPTR));
        ckbInsertCRC->setText(QApplication::translate("ModbusSlaver", "\350\207\252\345\212\250\346\267\273\345\212\240\346\240\241\351\252\214\347\240\201", Q_NULLPTR));
        rdbRTU->setText(QApplication::translate("ModbusSlaver", "RTU", Q_NULLPTR));
        rdbASCII->setText(QApplication::translate("ModbusSlaver", "ASCII", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        txtAddr->setToolTip(QApplication::translate("ModbusSlaver", "\344\273\216\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        txtAddr->setText(QApplication::translate("ModbusSlaver", "01", Q_NULLPTR));
        toolButton->setText(QApplication::translate("ModbusSlaver", "\346\270\205\347\251\272", Q_NULLPTR));
        btnSave->setText(QApplication::translate("ModbusSlaver", "\344\277\235\345\255\230", Q_NULLPTR));
        btnLoad->setText(QApplication::translate("ModbusSlaver", "\345\212\240\350\275\275", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        txtCoilNum->setToolTip(QApplication::translate("ModbusSlaver", "\346\225\260\351\207\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        txtCoilNum->setPlaceholderText(QApplication::translate("ModbusSlaver", "\346\225\260\351\207\217", Q_NULLPTR));
        ckbCoilHideAddr->setText(QApplication::translate("ModbusSlaver", "\351\232\220\350\227\217\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        txtCoilStartAddr->setToolTip(QApplication::translate("ModbusSlaver", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        txtCoilStartAddr->setPlaceholderText(QApplication::translate("ModbusSlaver", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
        ckbCoilHideAlias->setText(QApplication::translate("ModbusSlaver", "\351\232\220\350\227\217\345\210\253\345\220\215", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ModbusSlaver", "Coil", Q_NULLPTR));
        ckbRegHideAlias->setText(QApplication::translate("ModbusSlaver", "\351\232\220\350\227\217\345\210\253\345\220\215", Q_NULLPTR));
        ckbRegHideAddr->setText(QApplication::translate("ModbusSlaver", "\351\232\220\350\227\217\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        txtRegStartAddr->setToolTip(QApplication::translate("ModbusSlaver", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        txtRegStartAddr->setPlaceholderText(QApplication::translate("ModbusSlaver", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        txtRegNum->setToolTip(QApplication::translate("ModbusSlaver", "\346\225\260\351\207\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        txtRegNum->setPlaceholderText(QApplication::translate("ModbusSlaver", "\346\225\260\351\207\217", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ModbusSlaver", "Reg", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("ModbusSlaver", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusSlaver: public Ui_ModbusSlaver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSSLAVER_H
