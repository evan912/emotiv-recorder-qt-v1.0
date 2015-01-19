#pragma once
#include <ctime>
#include <stdlib.h>  
#include <string>

class theDateTime
{
public:
	theDateTime(void);
	~theDateTime(void);

	std::string*  getDate();
	std::string*  getTime();

	long double year; 
	long double mon;  
	long double day;

	long double hour;   
	long double min;    
	long double second;

	std::string theDate;
	std::string theTime;


private:
	time_t t;
	struct tm * now;
};

