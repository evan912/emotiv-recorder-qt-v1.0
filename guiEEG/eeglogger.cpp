#include "eegLogger.h"

//declare channel list for Emotiv
EE_DataChannel_t targetChannelList[] = {
		ED_AF3, ED_F7, ED_F3, ED_FC5, ED_T7, 
		ED_P7, ED_O1, ED_O2, ED_P8, ED_T8, 
		ED_FC6, ED_F4, ED_F8, ED_AF4
};

const char header[] = "AF3,F7,F3, FC5, T7, P7, O1, O2,P8" 
                      ", T8, FC6, F4,F8, AF4";

eegLogger::eegLogger(void)
{
	//initialize variables
	eEvent				= EE_EmoEngineEventCreate();
	eState				= EE_EmoStateCreate();
	userID				= 0;
	secs				= 1;
	datarate			= 0;
	readytocollect		= false;
	option				= 0;
	state				= 0;
	isStop				= false;
	fileName			= "eegdata";
}

void eegLogger::run(){
	bool first = true;
	//SetCurrentDirectory(TEXT("D:/EEGProgram/LE_EEG Auto Recorder(with Open Close eyes sections)/PEBL Tests"));
	SetCurrentDirectory(TEXT("./data"));
	//SetCurrentDirectory(TEXT("..\\PEBL Tests"));
	//timeRecord << "EEG Logger starts: " << double (clock()-startTime)/CLOCKS_PER_SEC << endl;

	//establish a connection with Emotiv device
	if(EE_EngineConnect() != EDK_OK){
		throw std::exception("Emotiv Engine start up failed.");
		return;
	}
	//if connection is created successfully
	else{
		//create a file stream
		fileName.append(".txt");
		ofs = ofstream(fileName, ios::trunc);
		//ofs << header << endl;

		//Innitialize data handle and buffer
		hData = EE_DataCreate();
		EE_DataSetBufferSizeInSec(secs);

		//Start data acquisition
		while (!isStop) 
		{
			state = EE_EngineGetNextEvent(eEvent);

			if (state == EDK_OK) {

				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);
				EE_EmoEngineEventGetUserId(eEvent, &userID);

				// Log the EmoState if it has been updated
				if (eventType == EE_UserAdded) {
					EE_DataAcquisitionEnable(userID,true);
					readytocollect = true;
				}
			}

			if (readytocollect) 
			{

				EE_DataUpdateHandle(0, hData);

				unsigned int nSamplesTaken=0;
				EE_DataGetNumberOfSample(hData,&nSamplesTaken);

				if (nSamplesTaken != 0) {
					//record the start time of EEGLogger
					if(first){
						//timeRecord << "EEG Logger first record: " << double (clock()-startTime)/CLOCKS_PER_SEC << endl;
						first = false;
					}
					if(kbhit() && getch()==VK_SPACE){
						//timeRecord << "EEG for target: " << double (clock()-startTime)/CLOCKS_PER_SEC << endl;
					}
					//store data to a buffer
					double* data = new double[nSamplesTaken];
					for (int sampleIdx=0 ; sampleIdx<(int)nSamplesTaken ; ++ sampleIdx) {
						for (int i = 0 ; i<sizeof(targetChannelList)/sizeof(EE_DataChannel_t) ; i++) {

							EE_DataGet(hData, targetChannelList[i], data, nSamplesTaken);
							ofs << data[sampleIdx] << ",";
						}	
						ofs << endl;
					}
					delete[] data;
				}

			}
			Sleep(100);
		}
	}
	//free memory
	ofs.close();
	EE_DataFree(hData);
	EE_EngineDisconnect();
	EE_EmoStateFree(eState);
	EE_EmoEngineEventFree(eEvent);
	//qApp->quit();
	SetCurrentDirectory(TEXT("../"));

}

eegLogger::~eegLogger(void)
{
}
