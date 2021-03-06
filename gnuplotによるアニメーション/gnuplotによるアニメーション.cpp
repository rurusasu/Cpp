// gnuplotによるアニメーション.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Windows.h"
#include "WinBase.h"

using namespace std;

int main()
{
	FILE *gp, *fp1, *fp2;
	int i, nod;
	//初期配置
	double X[9][2] = { {0.0,0.0},{0.1,0.0},{0.2,0.0},{0.0,0.1},{0.1,0.1},{0.2,0.1},{0.0,0.2},{0.1,0.2},{0.2,0.2} };

	//Animation settigs
	//gnuplotを動かすためのコマンド
	if ((gp = _popen("gnuplot", "w")) == NULL) {
		printf("gnuplot open erorr!!\n");
		exit(EXIT_FAILURE);
	}

	//gnuplotの操作
	fprintf(gp, "set size square\n");              //figureを正方形に
	fprintf(gp, "set xrange [%f:%f] \n", 0.0, 3.0); //範囲の指定
	fprintf(gp, "set yrange [%f:%f] \n", 0.0, 3.0);
	fprintf(gp, "set xlabel '時間' \n");  //軸ラベルを設定
	fprintf(gp, "set ylabel '人口' \n");
	fprintf(gp, "unset key \n");         //凡例を表示しない

	//点の位置を動かす
	for (i = 0; i < 30; i++) {
		fopen_s(&fp1,"move_point.dat", "w"); //上書きモードでファイルを開く
		fopen_s(&fp2, "move_point.txt", "w");
		fprintf(gp, "set title 't = %d' \n", i); //タイトルを設定
		for (nod = 0; nod < 9; nod++) {
			fprintf(fp1, "%f %f \n", X[nod][0], X[nod][1]); //点nodの位置をファイルに書き込み
			fprintf(fp2, "%f %f \n", X[nod][0], X[nod][1]);
			X[nod][0] += 0.1; X[nod][1] += 0.1;
		}
		fprintf(gp, "plot 'move_point.dat' w p pt 7 ps 0.5\n");  //gnuplotで点を描く
		fclose(fp1);  //位置を書いているファイルを閉じる
		fclose(fp2);
		fflush(gp);  //バッファに格納されているデータを吐き出す
		Sleep(100);
	}
	fprintf(gp, "exit\n");  //gnuplotの終了
	fflush(gp); //バッファに格納されているデータを吐き出す
	_pclose(gp);
}

