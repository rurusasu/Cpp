// 一次拡散方程式（一次熱拡散方程式）.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int L = 100;       //系の長さ
const int N = L + 1;     //点の数（端があるので長さ + 1）
const int LOOP = 100;    //繰り返しの回数
const double dt = 0.5;
const double A = 10;     //端の温度

//変数
double T[N];  //温度のデータ
double T2[N]; //温度のデータのテンポラリ変数（変数の内容を一時的に退避させる変数）


int main()
{
    //値の初期化
	for (int i = 0; i < N; i++) T[i] = 0;

	//境界条件
	T[0] = 0;
	T[N - 1] = A;

	//メインループ
	for (int j = 0; j < LOOP; j++) {
		//次のステップの温度を計算
		for (int i = 1; i < N - 1; i++)
			T2[i] = T[i] + (T[i + 1] - 2 * T[i] + T[i - 1])*dt;

		//次のステップの値をコピー
		for (int i = 1; i < N-1; i++)
			T[i] = T2[i];
	}
	//結果の出力
	for (int i = 0; i < N; i++)
		cout <<"端からの距離"<< i <<"温度"<< T[i]<<"（℃）\n";
}

