#include <stdio.h>

int main(void) 
{
	FILE* fp;

	if ((fopen_s(&fp, "data.txt", "r")) != 0)
		printf("�t�@�C�����J���܂���ł����B");
	else
	{
		// ����
		fprintf(fp, "Hello world");

		fclose(fp);
	}

	return 0;
}