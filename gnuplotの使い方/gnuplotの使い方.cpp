// gnuplotの使い方.cpp : Defines the entry point for the console application.
//


//gnuplotを試験的にc++から実行する
#include "stdafx.h"
#include "iostream"
#include "cstdio"

using namespace std;

int main()
{
	FILE *fp = _popen("gnuplot.exe", "w");
	if (fp == NULL)
		return -1;
	fputs("plot sin(x)\n", fp);
	fflush(fp);
	cin.get();
	_pclose(fp);
}