#ifndef GUIEEG_H
#define GUIEEG_H

#include <QtWidgets/QMainWindow>
#include "ui_guieeg.h"
#include "eegLogger.h"
#include "theDateTime.h"
#include "DigitalClock.h"

class guiEEG : public QMainWindow
{
	Q_OBJECT

public:
	guiEEG(QWidget *parent = 0);
	~guiEEG();
	void connectDeviceSaveData();
	void connectDeviceOnly();
	void updateRemainTime();



	eegLogger* myeeglogger;
	theDateTime* myDataTime;
	QTimer *myTimerOneSecond;
	QTimer *myTimer1;
	QTimer *myTimer2_cus;

	
	

private:
	Ui::guiEEGClass ui;
	bool is1minRecording;
	bool isCusRecording;
	bool isLongRecording;
	long int runTimeCounter;
	long int startLongRecord;
	long int currentLongRecord;

	QString setDataFilename (void);


	public slots:
		void on_pushButton_1min_record_clicked();
		void on_pushButton_long_record_clicked();
		void on_pushButton_cus_record_clicked();
		void on_pushButton_2_stop_clicked();
		void on_pushButton_open_clicked();
		void disconnectDevice();
		void update_time_label();
};

#endif // GUIEEG_H
