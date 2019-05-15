#include "Log.h"

int main()
{
	printlog("test %d", 124);
	printlog(L"test %X", 0x1234);
	return 0;
}