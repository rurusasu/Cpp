#include <Windows.h>
#include <iostream>
#include <clocale>

int main()
{
	int n = 2000; // 繰り返し回数
	LONGLONG usec_buff = 0;
	LONGLONG usec_std = 0;

	std::setlocale(LC_ALL, "Japanese_Jpn.932");

	LARGE_INTEGER frequency;
	BOOL ret = QueryPerformanceFrequency(&frequency); // タイマの周波数を取得
	if (ret == 0) {
		std::wcerr << L"この計算機は高精度タイマーをサポートしていません。" << std::endl;
		return 1;
	}
	std::wcout << L"この計算機の高精度タイマー分解能は、" << frequency.QuadPart << L" Hzです。" << std::endl; // この計算機の高精度タイマー分解能は、10,000,000 Hzです。

	for (int i = 1; i < n+1; i++)
	{
		// 時間計測したい始点でカウンタを取得
		LARGE_INTEGER start;
		QueryPerformanceCounter(&start);

		std::wcout << i << L" Hello! World" << std::endl;

		// 時間計測したい終点でカウンタを取得
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);

		// カウンタの差分を周波数で割れば経過時間を「秒」で取得できる。
		LONGLONG span = end.QuadPart - start.QuadPart;
		double sec = (double)span / (double)frequency.QuadPart;

		LONGLONG usec = (span * 1000000L) / frequency.QuadPart;
		usec_buff = usec_buff + usec;

		std::wcout << L"文字を表示するのにかかる時間は" << sec << L"秒です。" << std::endl;
		std::wcout << L"文字を表示するのにかかる時間は" << usec << L"μ秒です。\n\r" << std::endl;
	}
	usec_std = usec_buff / n;
	std::wcout << L"平均所要時間は" << usec_std << L"μ秒です。" << std::endl;
}





