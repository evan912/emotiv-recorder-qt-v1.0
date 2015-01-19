#include "guieegUI.h"
#include <stdlib.h>
#include <iostream>
#include <QFileInfo>
#include <QDesktopServices>



guiEEG::guiEEG(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label_msg->setText("Recorder");
	myDataTime = new theDateTime;
	is1minRecording = false;
	isCusRecording = false;
	isLongRecording = false;
	runTimeCounter = 0;
	
	ui.pushButton_2_stop->setDisabled(true);	
	ui.spinBox_cus_time->setValue(10);
	ui.spinBox_cus_time->setMaximum(9999);
	ui.textBrowser_time->setText("00:00:00");
	ui.lineEdit_filename->setText("EEGData");

	// show a date label on UI.
	//ui.label_time->setText(__TIMESTAMP__);
	myDataTime->getDate();
	myDataTime->getTime();
	//ui.label_time->setText(QString::fromStdString(myDataTime->theDate));

	// update time browser.
	myTimerOneSecond = new QTimer(this);
	connect(myTimerOneSecond, SIGNAL(timeout()), this, SLOT(update_time_label()));
	myTimerOneSecond->start(1000);
}

guiEEG::~guiEEG()
{
	

}

void guiEEG::connectDeviceSaveData()
{
	myeeglogger = new eegLogger;
	// set file name from UI
	myeeglogger->fileName = setDataFilename().toStdString();

	myeeglogger->isStop=false;
	myeeglogger->start();

	ui.pushButton_1min_record->setEnabled(false);
	ui.pushButton_long_record->setEnabled(false);
	ui.pushButton_cus_record->setEnabled(false);
	ui.spinBox_cus_time->setEnabled(false);
	ui.pushButton_open->setEnabled(false);
	ui.pushButton_2_stop->setEnabled(true);
}

void guiEEG::disconnectDevice()
{
	myeeglogger->isStop=true;
	ui.label_msg->setText("Recording stopped.");	

	if (is1minRecording)
	{
		delete myTimer1;
		is1minRecording = false;
	}
	if(isCusRecording)
	{ 
		delete myTimer2_cus;
		isCusRecording = false;
	}
	if (isLongRecording)
	{
		isLongRecording = false;
	}

	ui.pushButton_1min_record->setEnabled(true);
	ui.pushButton_long_record->setEnabled(true);
	ui.pushButton_cus_record->setEnabled(true);
	ui.spinBox_cus_time->setEnabled(true);
	ui.pushButton_open->setEnabled(true);
	ui.pushButton_2_stop->setEnabled(false);
}

void guiEEG::connectDeviceOnly()
{
	
}

void guiEEG::updateRemainTime()
{

}

void guiEEG::on_pushButton_long_record_clicked()
{
	connectDeviceSaveData();
	ui.label_msg->setText("Start Recording...");
	isLongRecording = true;
	startLongRecord = runTimeCounter;
}

void guiEEG::on_pushButton_1min_record_clicked()
{
	
	connectDeviceSaveData();

	// set timer of 1 min
	myTimer1 = new QTimer(this);
	connect (myTimer1, SIGNAL(timeout()), this, SLOT(disconnectDevice()));
	myTimer1->start(1000*60);

	ui.label_msg->setText("Start 1 min Recording...");
	is1minRecording = true;

}

void guiEEG::on_pushButton_cus_record_clicked()
{
	connectDeviceSaveData();

	// set timer of custom minutes.
	myTimer2_cus = new QTimer(this);
	connect (myTimer2_cus, SIGNAL(timeout()), this, SLOT(disconnectDevice()));

	// read time from UI
	int cus_time = ui.spinBox_cus_time->value();
	myTimer2_cus->start(1000*60*cus_time);

	ui.label_msg->setText("Start "+ QString::number(cus_time)+ " minutes Recording...");
	isCusRecording = true;
}

void guiEEG::on_pushButton_2_stop_clicked()
{
	disconnectDevice();
	ui.textBrowser_time->setText("00:00:00");
}

void guiEEG::update_time_label()
{
	DigitalClock myclock;
	QString remainTime;
	if(is1minRecording)
	{
		remainTime = myclock.convertNumerToTimeFormat(myTimer1->remainingTime());
		ui.textBrowser_time->setText(remainTime);
	}
	else if (isCusRecording)
	{
		remainTime = myclock.convertNumerToTimeFormat(myTimer2_cus->remainingTime());
		ui.textBrowser_time->setText(remainTime);
	}
	else if (isLongRecording)
	{
		currentLongRecord = runTimeCounter;
		remainTime = myclock.convertNumerToTimeFormat((currentLongRecord-startLongRecord)*1000);
		ui.textBrowser_time->setText(remainTime);
	}

	myTimerOneSecond->start(1000);
	runTimeCounter++;
}

QString guiEEG::setDataFilename( void )
{
	theDateTime* dateAndTime = new theDateTime;
	QString filename = ui.lineEdit_filename->text();

	if (ui.checkBox_1_date->isChecked())
	{
		filename.append("_");
		dateAndTime->getDate();
		filename.append(QString::fromStdString(dateAndTime->theDate));
	}

	if (ui.checkBox_2_time->isChecked())
	{
		filename.append("_");
		dateAndTime->getTime();
		filename.append(QString::fromStdString(dateAndTime->theTime));
	}


	delete dateAndTime;

	return filename;
}

void guiEEG::on_pushButton_open_clicked()
{
	//QDesktopServices::openUrl(QUrl("file:///C:/Users/Hxy/Documents/Visual Studio 2010/Projects/guiEEG/guiEEG",QUrl::TolerantMode));
	QString path ="file:///" ;
	path.append(QFileInfo("data").absoluteFilePath());
	/*path.append("/data");*/
	QDesktopServices::openUrl(QUrl(path,QUrl::TolerantMode));
	
}


