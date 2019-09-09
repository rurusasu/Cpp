#include <Windows.h>
#include <iostream>
#include <clocale>

int main()
{
	int n = 2000; // �J��Ԃ���
	LONGLONG usec_buff = 0;
	LONGLONG usec_std = 0;

	std::setlocale(LC_ALL, "Japanese_Jpn.932");

	LARGE_INTEGER frequency;
	BOOL ret = QueryPerformanceFrequency(&frequency); // �^�C�}�̎��g�����擾
	if (ret == 0) {
		std::wcerr << L"���̌v�Z�@�͍����x�^�C�}�[���T�|�[�g���Ă��܂���B" << std::endl;
		return 1;
	}
	std::wcout << L"���̌v�Z�@�̍����x�^�C�}�[����\�́A" << frequency.QuadPart << L" Hz�ł��B" << std::endl; // ���̌v�Z�@�̍����x�^�C�}�[����\�́A10,000,000 Hz�ł��B

	for (int i = 1; i < n+1; i++)
	{
		// ���Ԍv���������n�_�ŃJ�E���^���擾
		LARGE_INTEGER start;
		QueryPerformanceCounter(&start);

		std::wcout << i << L" Hello! World" << std::endl;

		// ���Ԍv���������I�_�ŃJ�E���^���擾
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);

		// �J�E���^�̍��������g���Ŋ���Όo�ߎ��Ԃ��u�b�v�Ŏ擾�ł���B
		LONGLONG span = end.QuadPart - start.QuadPart;
		double sec = (double)span / (double)frequency.QuadPart;

		LONGLONG usec = (span * 1000000L) / frequency.QuadPart;
		usec_buff = usec_buff + usec;

		std::wcout << L"������\������̂ɂ����鎞�Ԃ�" << sec << L"�b�ł��B" << std::endl;
		std::wcout << L"������\������̂ɂ����鎞�Ԃ�" << usec << L"�ʕb�ł��B\n\r" << std::endl;
	}
	usec_std = usec_buff / n;
	std::wcout << L"���Ϗ��v���Ԃ�" << usec_std << L"�ʕb�ł��B" << std::endl;
}





