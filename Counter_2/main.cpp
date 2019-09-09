#include <windows.h>
#include <stdio.h>
int main(void)
{
	LARGE_INTEGER liBegin, liEnd, liFreq;
	QueryPerformanceCounter(&liBegin);
	Sleep(1000);
	QueryPerformanceCounter(&liEnd);
	QueryPerformanceFrequency(&liFreq);
	printf("%f\n", (double)(liEnd.QuadPart - liBegin.QuadPart) / (double)liFreq.QuadPart);
	return 0;
}