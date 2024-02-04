#include "Log.h"
#include <windows.h>
#pragma warning(disable:4996)
void Log(char* fmt, ...)
{
	_SYSTEMTIME sTime;
	GetSystemTime(&sTime);
	char buf[1024] = {0};
	va_list va_alist;
	std::ofstream output;

	va_start(va_alist, fmt);
	vsnprintf(buf, sizeof(buf), fmt, va_alist);
	va_end(va_alist);

	output.open("Framework-Log.txt", std::ios::app);
	if(output.fail()) return;
	output<<"["<<sTime.wHour<<":"<<sTime.wMinute<<":"<<sTime.wSecond<<"] "<<buf<< std::endl;
	output.close();
}