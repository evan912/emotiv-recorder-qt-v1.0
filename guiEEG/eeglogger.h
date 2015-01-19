#pragma once

#include <qthread.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <QTimer>


//external file for Emotiv
#include "include/EmoStateDLL.h"
#include "include/edk.h"
#include "include/edkErrorCode.h"
#pragma comment(lib, "./lib/edk.lib")

using namespace std;

class eegLogger : public QThread
{
public:
	eegLogger(void);
	~eegLogger(void);
	void run();
	//global variables
	bool isStop;
	string fileName;

private:
	//declare variables for Emotiv
	EmoEngineEventHandle eEvent;
	EmoStateHandle eState;
	unsigned int userID;
	float secs;
	unsigned int datarate;
	bool readytocollect;
	int option;
	int state;
	ofstream ofs;
	DataHandle hData;

		
};
