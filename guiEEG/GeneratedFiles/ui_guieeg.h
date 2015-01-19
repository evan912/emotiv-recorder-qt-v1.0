/********************************************************************************
** Form generated from reading UI file 'guieeg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIEEG_H
#define UI_GUIEEG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiEEGClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_1min_record;
    QTextBrowser *textBrowser_time;
    QLabel *label_msg;
    QPushButton *pushButton_2_stop;
    QPushButton *pushButton_long_record;
    QPushButton *pushButton_cus_record;
    QLabel *label;
    QSpinBox *spinBox_cus_time;
    QLabel *label_2;
    QCheckBox *checkBox_1_date;
    QCheckBox *checkBox_2_time;
    QLineEdit *lineEdit_filename;
    QPushButton *pushButton_open;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiEEGClass)
    {
        if (guiEEGClass->objectName().isEmpty())
            guiEEGClass->setObjectName(QStringLiteral("guiEEGClass"));
        guiEEGClass->resize(475, 303);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../Pictures/eeglogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        guiEEGClass->setWindowIcon(icon);
        centralWidget = new QWidget(guiEEGClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_1min_record = new QPushButton(centralWidget);
        pushButton_1min_record->setObjectName(QStringLiteral("pushButton_1min_record"));
        pushButton_1min_record->setGeometry(QRect(140, 120, 91, 41));
        textBrowser_time = new QTextBrowser(centralWidget);
        textBrowser_time->setObjectName(QStringLiteral("textBrowser_time"));
        textBrowser_time->setGeometry(QRect(350, 30, 101, 31));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        textBrowser_time->setFont(font);
        textBrowser_time->setLayoutDirection(Qt::LeftToRight);
        textBrowser_time->setAutoFillBackground(true);
        textBrowser_time->setInputMethodHints(Qt::ImhMultiLine|Qt::ImhTime);
        label_msg = new QLabel(centralWidget);
        label_msg->setObjectName(QStringLiteral("label_msg"));
        label_msg->setGeometry(QRect(30, 30, 321, 31));
        QFont font1;
        font1.setPointSize(10);
        label_msg->setFont(font1);
        label_msg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_2_stop = new QPushButton(centralWidget);
        pushButton_2_stop->setObjectName(QStringLiteral("pushButton_2_stop"));
        pushButton_2_stop->setGeometry(QRect(30, 180, 201, 41));
        pushButton_2_stop->setAutoFillBackground(false);
        pushButton_2_stop->setStyleSheet(QStringLiteral("border-color: rgb(255, 0, 0);"));
        pushButton_long_record = new QPushButton(centralWidget);
        pushButton_long_record->setObjectName(QStringLiteral("pushButton_long_record"));
        pushButton_long_record->setGeometry(QRect(30, 120, 91, 41));
        pushButton_cus_record = new QPushButton(centralWidget);
        pushButton_cus_record->setObjectName(QStringLiteral("pushButton_cus_record"));
        pushButton_cus_record->setGeometry(QRect(350, 120, 101, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 130, 31, 21));
        spinBox_cus_time = new QSpinBox(centralWidget);
        spinBox_cus_time->setObjectName(QStringLiteral("spinBox_cus_time"));
        spinBox_cus_time->setGeometry(QRect(260, 120, 61, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 71, 16));
        checkBox_1_date = new QCheckBox(centralWidget);
        checkBox_1_date->setObjectName(QStringLiteral("checkBox_1_date"));
        checkBox_1_date->setGeometry(QRect(250, 80, 70, 17));
        checkBox_2_time = new QCheckBox(centralWidget);
        checkBox_2_time->setObjectName(QStringLiteral("checkBox_2_time"));
        checkBox_2_time->setGeometry(QRect(350, 80, 70, 17));
        lineEdit_filename = new QLineEdit(centralWidget);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));
        lineEdit_filename->setGeometry(QRect(90, 80, 141, 20));
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setGeometry(QRect(250, 180, 201, 41));
        guiEEGClass->setCentralWidget(centralWidget);
        label_msg->raise();
        pushButton_1min_record->raise();
        textBrowser_time->raise();
        pushButton_2_stop->raise();
        pushButton_long_record->raise();
        pushButton_cus_record->raise();
        label->raise();
        spinBox_cus_time->raise();
        label_2->raise();
        checkBox_1_date->raise();
        checkBox_2_time->raise();
        lineEdit_filename->raise();
        pushButton_open->raise();
        menuBar = new QMenuBar(guiEEGClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 475, 21));
        guiEEGClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(guiEEGClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        guiEEGClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(guiEEGClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        guiEEGClass->setStatusBar(statusBar);

        retranslateUi(guiEEGClass);

        QMetaObject::connectSlotsByName(guiEEGClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiEEGClass)
    {
        guiEEGClass->setWindowTitle(QApplication::translate("guiEEGClass", "EEG-Recorder-v1.0", 0));
        pushButton_1min_record->setText(QApplication::translate("guiEEGClass", "1 min Record", 0));
        label_msg->setText(QApplication::translate("guiEEGClass", "TextLabel", 0));
        pushButton_2_stop->setText(QApplication::translate("guiEEGClass", "Stop", 0));
        pushButton_long_record->setText(QApplication::translate("guiEEGClass", "Record", 0));
        pushButton_cus_record->setText(QApplication::translate("guiEEGClass", "Custom Record", 0));
        label->setText(QApplication::translate("guiEEGClass", "Min", 0));
        label_2->setText(QApplication::translate("guiEEGClass", "File Name:", 0));
        checkBox_1_date->setText(QApplication::translate("guiEEGClass", "+ date", 0));
        checkBox_2_time->setText(QApplication::translate("guiEEGClass", "+ time", 0));
        pushButton_open->setText(QApplication::translate("guiEEGClass", "Open Folder", 0));
    } // retranslateUi

};

namespace Ui {
    class guiEEGClass: public Ui_guiEEGClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIEEG_H
