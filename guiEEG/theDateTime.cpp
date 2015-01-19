#include "theDateTime.h"



theDateTime::theDateTime(void)
{
	 t=time(0);
	 now = new struct tm;
	 now = localtime( & t );
}


theDateTime::~theDateTime(void)
{
}

std::string* theDateTime::getDate()
{
	year =(now->tm_year + 1900);
	mon  =(now->tm_mon + 1);
	day  = (now->tm_mday);
	theDate=std::to_string(year);
	theDate.append("_");
	theDate.append(std::to_string(mon));
	theDate.append("_");
	theDate.append(std::to_string(day));

	return &theDate;
}

std::string* theDateTime::getTime()
{
	long double hour   =(now->tm_hour);
	long double min    =(now->tm_min);
	long double second = (now->tm_sec);

	if (hour>9)
	{
		theTime=(std::to_string(hour));
	}
	else
	{
		theTime.append("0");
		theTime.append(std::to_string(hour));
	}	
	theTime.append("_");
	if (min>9)
	{
		theTime.append(std::to_string(min));
	}
	else
	{
		theTime.append("0");
		theTime.append(std::to_string(min));
	}	

	theTime.append("_");

	if (second>9)
	{
		theTime.append(std::to_string(second));
	}
	else
	{
		theTime.append("0");
		theTime.append(std::to_string(second));
	}	
	

	return &theTime;
}

