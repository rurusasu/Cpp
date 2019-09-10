#include <stdio.h>

int main(void) 
{
	FILE* fp;

	if ((fopen_s(&fp, "data.txt", "r")) != 0)
		printf("ファイルを開けませんでした。");
	else
	{
		// 処理
		fprintf(fp, "Hello world");

		fclose(fp);
	}

	return 0;
}