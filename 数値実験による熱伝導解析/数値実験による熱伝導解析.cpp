// 数値実験による熱伝導解析.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"

using namespace std;

const double L = 0.8;   //棒の長さ[m]
const double Q1 = 700;  //左端の温度[℃]
const double Q2 = 0;    //右端の温度[℃]
const double init = 350; //棒の初期温度[℃]
const int l = 10;  //棒の分割回数
const int LOOP = 1000; //繰り返し回数

//グラフにプロットする列の指定
const int plot1 = 0; //'0'の時、初期値をplot
const int plot2 = 100;
const int plot3 = 200;
const int plot4 = 1000;


//微小変位
double dx = L / l;
double dt = 1;

//金属の物性値
const double r = 8960;   //密度[kg/m3]
const double c = 385;    //比熱
const double k = 390;    //熱伝導率
const double a = k / (c*r);  //熱拡散係数

//比例定数
const double dx2 = pow(dx, 2);
const double p = a * dt / dx2;

const int N = l + 1;
const int LOOP_ = LOOP + 1;
double T[N][LOOP_];
double X[N];

//plotの軸範囲
const double X_ = L;  //gnuplotの軸範囲は'double'
const double Y_ = Q1;

//関数
void Init(void);
void culculation(void);
void write(void);
void plot(void);

void Init(void)
{
	for (int i = 0; i < N; i++) {
		X[i] = dx * i;
		for (int j = 0; j < LOOP_; j++) {
			if (i == 0) T[i][j] = Q1;
			else if (j == 0) T[i][j] = init;
			else T[i][j] = 1;
			if (i == l) T[i][j] = Q2;
		}
	}
}

void culculation(void)
{
	for (int j = 1; j < LOOP_; j++) {
		for (int i = 1; i < N-1; i++) {
			T[i][j] = p * T[i + 1][j - 1] + (1 - 2 * p)*T[i][j - 1] + p * T[i - 1][j - 1];
		}
	}
}

void write(void)
{
	FILE *fp;

	fopen_s(&fp, "ondo.txt", "w");
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%f ", X[i]);
		for (int j = 0; j < LOOP_; j++) {
			fprintf(fp, "%010f ", T[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void plot(void)
{
	FILE *gp;
	//gnuplotを動かすためのコマンド
	if ((gp = _popen("gnuplot -persist", "w")) == NULL) {
		printf("gunplot open erorr!!\n");
		exit(EXIT_FAILURE);
	}

	//gnuplotの操作
	fprintf(gp, "set size square\n");
	fprintf(gp, "set xrange [%f:%f ]\n", 0.0, X_); //範囲の指定
	fprintf(gp, "set yrange [%f:%f] \n", 0.0, Y_);
	fprintf(gp, "set xlabel '位置 x[m]'  \n"); //軸ラベルを設定
	fprintf(gp, "set ylabel '温度 T[℃]' \n");
	fprintf(gp, "unset key \n");   //凡例を表示しない
	
	//gnuplotへの出力
	fprintf(gp, "plot '-' with lines, '-' with lines, '-' with lines, '-' with lines\n");
	for (int i = 0; i < N; i++) fprintf(gp, "%f %f\n", X[i], T[i][plot1]); fprintf(gp, "e\n"); fflush(gp); //gnuplotで線を描く
	for (int i = 0; i < N; i++) fprintf(gp, "%f %f\n", X[i], T[i][plot4]); fprintf(gp, "e\n"); fflush(gp);
	for (int i = 0; i < N; i++) fprintf(gp, "%f %f\n", X[i], T[i][plot3]); fprintf(gp, "e\n"); fflush(gp);
	for (int i = 0; i < N; i++) fprintf(gp, "%f %f\n", X[i], T[i][plot4]); fprintf(gp, "e\n"); fflush(gp);
	fprintf(gp, "quit\n");
	_pclose(gp);
}

int main()
{
	Init();
	culculation();
	write();
	plot();
}