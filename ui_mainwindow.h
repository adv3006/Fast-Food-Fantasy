/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_12;
    QLabel *label_11;
    QWidget *page_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_6;
    QPushButton *CustomList_Button;
    QPushButton *ChoiceNumber_Button;
    QPushButton *ViewAll_Buton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QTextBrowser *textBrowser_3;
    QWidget *page_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AddRestaurant_Button;
    QPushButton *pushButton_8;
    QPushButton *AddMenu_Button;
    QPushButton *deleteItem_Button;
    QPushButton *ChangePrice_B;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *Restauraunt_Info;
    QTableWidget *Menu_Table;
    QPushButton *pushButton_4;
    QLabel *confirmDeleteLabel;
    QDialogButtonBox *confirmDeleteButton;
    QWidget *page_5;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *Name_Edit;
    QLabel *label_7;
    QLineEdit *Number_Edit;
    QLabel *label_8;
    QLineEdit *Distance_Edit;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QTableWidget *Menu_Table_2;
    QGridLayout *gridLayout_2;
    QPushButton *AddItem_Button;
    QPushButton *DeleteItem2_Button;
    QLabel *label_10;
    QLineEdit *distance_edit;
    QLabel *name_label;
    QPushButton *nextRestaurant_Button;
    QLabel *confirmDeleteLabel_2;
    QDialogButtonBox *confirmDeleteButton_2;
    QWidget *page_6;
    QPushButton *pushButton_9;
    QTableWidget *tableWidget;
    QLabel *label_13;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(914, 586);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 881, 531));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setFrameShape(QFrame::NoFrame);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 30, 751, 91));
        QFont font;
        font.setFamily(QStringLiteral("Raavi"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 110, 561, 401));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout_5->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(559, 335));
        label_11->setPixmap(QPixmap(QString::fromUtf8("SaddlebackLogo.jpg")));
        label_11->setScaledContents(true);

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayoutWidget = new QWidget(page_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 211, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        CustomList_Button = new QPushButton(verticalLayoutWidget);
        CustomList_Button->setObjectName(QStringLiteral("CustomList_Button"));

        verticalLayout->addWidget(CustomList_Button);

        ChoiceNumber_Button = new QPushButton(verticalLayoutWidget);
        ChoiceNumber_Button->setObjectName(QStringLiteral("ChoiceNumber_Button"));

        verticalLayout->addWidget(ChoiceNumber_Button);

        ViewAll_Buton = new QPushButton(verticalLayoutWidget);
        ViewAll_Buton->setObjectName(QStringLiteral("ViewAll_Buton"));

        verticalLayout->addWidget(ViewAll_Buton);

        layoutWidget1 = new QWidget(page_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 450, 671, 61));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 50, 266, 39));
        QFont font1;
        font1.setFamily(QStringLiteral("Hannotate TC"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        textBrowser_3 = new QTextBrowser(page_3);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(242, 92, 581, 331));
        QFont font2;
        font2.setFamily(QStringLiteral("Hannotate TC"));
        textBrowser_3->setFont(font2);
        textBrowser_3->setFrameShape(QFrame::StyledPanel);
        textBrowser_3->setLineWidth(1);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayoutWidget_2 = new QWidget(page_4);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 20, 192, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AddRestaurant_Button = new QPushButton(verticalLayoutWidget_2);
        AddRestaurant_Button->setObjectName(QStringLiteral("AddRestaurant_Button"));

        verticalLayout_2->addWidget(AddRestaurant_Button);

        pushButton_8 = new QPushButton(verticalLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout_2->addWidget(pushButton_8);

        AddMenu_Button = new QPushButton(verticalLayoutWidget_2);
        AddMenu_Button->setObjectName(QStringLiteral("AddMenu_Button"));

        verticalLayout_2->addWidget(AddMenu_Button);

        deleteItem_Button = new QPushButton(verticalLayoutWidget_2);
        deleteItem_Button->setObjectName(QStringLiteral("deleteItem_Button"));

        verticalLayout_2->addWidget(deleteItem_Button);

        ChangePrice_B = new QPushButton(verticalLayoutWidget_2);
        ChangePrice_B->setObjectName(QStringLiteral("ChangePrice_B"));

        verticalLayout_2->addWidget(ChangePrice_B);

        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 10, 341, 41));
        QFont font3;
        font3.setPointSize(16);
        label_3->setFont(font3);
        comboBox = new QComboBox(page_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 360, 171, 31));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 80, 111, 20));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(650, 80, 59, 16));
        layoutWidget2 = new QWidget(page_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(200, 100, 631, 331));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Restauraunt_Info = new QTextBrowser(layoutWidget2);
        Restauraunt_Info->setObjectName(QStringLiteral("Restauraunt_Info"));

        horizontalLayout->addWidget(Restauraunt_Info);

        Menu_Table = new QTableWidget(layoutWidget2);
        if (Menu_Table->columnCount() < 2)
            Menu_Table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Menu_Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Menu_Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Menu_Table->setObjectName(QStringLiteral("Menu_Table"));
        Menu_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Menu_Table->setSortingEnabled(true);

        horizontalLayout->addWidget(Menu_Table);

        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(700, 10, 113, 32));
        confirmDeleteLabel = new QLabel(page_4);
        confirmDeleteLabel->setObjectName(QStringLiteral("confirmDeleteLabel"));
        confirmDeleteLabel->setGeometry(QRect(430, 450, 391, 20));
        confirmDeleteButton = new QDialogButtonBox(page_4);
        confirmDeleteButton->setObjectName(QStringLiteral("confirmDeleteButton"));
        confirmDeleteButton->setGeometry(QRect(520, 470, 164, 32));
        confirmDeleteButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        layoutWidget_2 = new QWidget(page_5);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 421, 211));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        Name_Edit = new QLineEdit(layoutWidget_2);
        Name_Edit->setObjectName(QStringLiteral("Name_Edit"));

        gridLayout->addWidget(Name_Edit, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        Number_Edit = new QLineEdit(layoutWidget_2);
        Number_Edit->setObjectName(QStringLiteral("Number_Edit"));

        gridLayout->addWidget(Number_Edit, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setWordWrap(true);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        Distance_Edit = new QLineEdit(layoutWidget_2);
        Distance_Edit->setObjectName(QStringLiteral("Distance_Edit"));

        gridLayout->addWidget(Distance_Edit, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(page_5);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(500, 480, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget_3 = new QWidget(page_5);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(489, 20, 371, 341));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        Menu_Table_2 = new QTableWidget(layoutWidget_3);
        if (Menu_Table_2->columnCount() < 2)
            Menu_Table_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Menu_Table_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Menu_Table_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        Menu_Table_2->setObjectName(QStringLiteral("Menu_Table_2"));
        Menu_Table_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Menu_Table_2->setAlternatingRowColors(true);
        Menu_Table_2->setSortingEnabled(true);

        verticalLayout_3->addWidget(Menu_Table_2);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        AddItem_Button = new QPushButton(layoutWidget_3);
        AddItem_Button->setObjectName(QStringLiteral("AddItem_Button"));

        gridLayout_2->addWidget(AddItem_Button, 0, 0, 1, 1);

        DeleteItem2_Button = new QPushButton(layoutWidget_3);
        DeleteItem2_Button->setObjectName(QStringLiteral("DeleteItem2_Button"));

        gridLayout_2->addWidget(DeleteItem2_Button, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        label_10 = new QLabel(page_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 270, 311, 20));
        distance_edit = new QLineEdit(page_5);
        distance_edit->setObjectName(QStringLiteral("distance_edit"));
        distance_edit->setGeometry(QRect(260, 310, 71, 21));
        name_label = new QLabel(page_5);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(51, 310, 211, 21));
        nextRestaurant_Button = new QPushButton(page_5);
        nextRestaurant_Button->setObjectName(QStringLiteral("nextRestaurant_Button"));
        nextRestaurant_Button->setGeometry(QRect(40, 360, 281, 32));
        confirmDeleteLabel_2 = new QLabel(page_5);
        confirmDeleteLabel_2->setObjectName(QStringLiteral("confirmDeleteLabel_2"));
        confirmDeleteLabel_2->setGeometry(QRect(450, 370, 391, 20));
        confirmDeleteButton_2 = new QDialogButtonBox(page_5);
        confirmDeleteButton_2->setObjectName(QStringLiteral("confirmDeleteButton_2"));
        confirmDeleteButton_2->setGeometry(QRect(540, 390, 164, 32));
        confirmDeleteButton_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        pushButton_9 = new QPushButton(page_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(70, 320, 131, 41));
        tableWidget = new QTableWidget(page_6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(290, 40, 571, 391));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSortingEnabled(true);
        label_13 = new QLabel(page_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 40, 211, 211));
        label_13->setPixmap(QPixmap(QString::fromUtf8("map-location-md.png")));
        label_13->setScaledContents(true);
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Saddleback Restaurant Tracker</span></p></body></html>", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Administrator Login", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Next", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Customers Press Next! </p></body></html>", 0));
        label_11->setText(QString());
        pushButton_6->setText(QApplication::translate("MainWindow", "Initial List", 0));
        CustomList_Button->setText(QApplication::translate("MainWindow", "Custom List", 0));
        ChoiceNumber_Button->setText(QApplication::translate("MainWindow", "Choice + Number", 0));
        ViewAll_Buton->setText(QApplication::translate("MainWindow", "View All Restaurants", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Back", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">Option Descriptions</span></p></body></html>", 0));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hannotate TC'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; text-decoration: underline;\">Initial List </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">Go to all Restaurants in the system</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:"
                        "'MS Shell Dlg 2'; font-size:14pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; text-decoration: underline;\">Custom List</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">Pick the restaurants you will like to go to </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:14pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; text-decoration: underline;\">Choi"
                        "ce + Number</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">Pick an initial restaurant and choose a number and the </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">program will give directions to the first restaurant </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">and the next closest restaurants based on the</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:1"
                        "4pt;\">number you chose</span></p></body></html>", 0));
        AddRestaurant_Button->setText(QApplication::translate("MainWindow", "Add Restaurant", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Add Restaurant from File", 0));
        AddMenu_Button->setText(QApplication::translate("MainWindow", "Add Menu Item", 0));
        deleteItem_Button->setText(QApplication::translate("MainWindow", "Delete Menu Item", 0));
        ChangePrice_B->setText(QApplication::translate("MainWindow", "Change Item Price", 0));
        label_3->setText(QApplication::translate("MainWindow", "Administrator Menu", 0));
        label_4->setText(QApplication::translate("MainWindow", "Restaurant Info", 0));
        label_5->setText(QApplication::translate("MainWindow", "Menu", 0));
        QTableWidgetItem *___qtablewidgetitem = Menu_Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Item", 0));
        QTableWidgetItem *___qtablewidgetitem1 = Menu_Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Price", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Logout", 0));
        confirmDeleteLabel->setText(QApplication::translate("MainWindow", "Are you sure you want to delete:  ?", 0));
        label_6->setText(QApplication::translate("MainWindow", "Restaurant Name: ", 0));
        label_7->setText(QApplication::translate("MainWindow", "Number: ", 0));
        label_8->setText(QApplication::translate("MainWindow", "Distance from Saddleback College", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Menu</p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem2 = Menu_Table_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Item", 0));
        QTableWidgetItem *___qtablewidgetitem3 = Menu_Table_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Price", 0));
        AddItem_Button->setText(QApplication::translate("MainWindow", "Add Item", 0));
        DeleteItem2_Button->setText(QApplication::translate("MainWindow", "Delete Item", 0));
        label_10->setText(QApplication::translate("MainWindow", "Please Enter the distance to each Restaurant: ", 0));
        name_label->setText(QApplication::translate("MainWindow", "Name:", 0));
        nextRestaurant_Button->setText(QApplication::translate("MainWindow", "Next Restaurant", 0));
        confirmDeleteLabel_2->setText(QApplication::translate("MainWindow", "Are you sure you want to delete:  ?", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Back", 0));
        label_13->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
