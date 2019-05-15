#ifndef LOG_H
#define LOG_H
#include <stdio.h>
#include <windows.h>

#define MAX_LOG_BUFFER 4096
#define MAX_TIME_BUFFER 30

void printlog(const char *format, ...);
void printlog(const wchar_t *format, ...);
#endif // !LOG_H