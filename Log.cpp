#include "Log.h"

void printlog(const char *format, ...)
{
#ifdef _DEBUG
	CHAR *log_buffer = new CHAR[MAX_LOG_BUFFER + 1];
	CHAR *time_buffer = new CHAR[MAX_TIME_BUFFER + 1];
	CHAR *buffer = new CHAR[MAX_TIME_BUFFER + MAX_LOG_BUFFER + 2];
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	va_list args;
	va_start(args, format);
	sprintf_s(time_buffer, MAX_TIME_BUFFER, "[%02d:%02d:%02d %02d-%02d-%04d]", sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wDay, sysTime.wMonth, sysTime.wYear);
	vsprintf_s(log_buffer, MAX_LOG_BUFFER, format, args);
	sprintf_s(buffer, MAX_TIME_BUFFER + MAX_LOG_BUFFER, "%s - %s\n", time_buffer, log_buffer);
	OutputDebugStringA(buffer);
	va_end(args);
	delete[]buffer;
	delete[]time_buffer;
	delete[]log_buffer;
#endif

}
void printlog(const wchar_t *format, ...)
{
#ifdef _DEBUG
	WCHAR *log_buffer = new WCHAR[MAX_LOG_BUFFER + 1];
	WCHAR *time_buffer = new WCHAR[MAX_TIME_BUFFER + 1];
	WCHAR *buffer = new WCHAR[MAX_LOG_BUFFER + MAX_TIME_BUFFER + 2];
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	va_list args;
	va_start(args, format);
	swprintf_s(time_buffer, MAX_TIME_BUFFER, L"[%02d:%02d:%02d %02d-%02d-%04d]", sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wDay, sysTime.wMonth, sysTime.wYear);
	vswprintf_s(log_buffer, MAX_LOG_BUFFER, format, args);
	swprintf_s(buffer, MAX_LOG_BUFFER + MAX_TIME_BUFFER, L"%s - %s\n", time_buffer, log_buffer);
	OutputDebugStringW(buffer);
	va_end(args);
	delete[]buffer;
	delete[]time_buffer;
	delete[]log_buffer;
#endif
}