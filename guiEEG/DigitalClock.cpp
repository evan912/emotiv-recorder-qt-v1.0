
#include "DigitalClock.h"
#include <QTime>


DigitalClock::DigitalClock()
{

	
}



DigitalClock::~DigitalClock(void)
{
}

QString DigitalClock::convertNumerToTimeFormat( int ms )
{


	int second = ms/1000;
	ss = second%60;
	int minute = second/60;
	mm = minute%60;
	int hour = minute/60;
	hh = hour;


	if (hh>9)
		time_hh = QString::number(hh);
	else if (hh>=0 && hh<=9)
		time_hh = "0"+QString::number(hh);
	else
		time_hh = "00";

	if (mm>9)
		time_mm = QString::number(mm);
	else if (mm>=0 && mm<=9)
		time_mm = "0"+QString::number(mm);
	else
		time_mm = "00";

	if (ss>9)
		time_ss = QString::number(ss);
	else if (ss>=0 && ss<=9)
		time_ss = "0"+QString::number(ss);
	else
		time_ss = "00";

	return numberToTimeFormat = time_hh + ":" + time_mm + ":" + time_ss;
}