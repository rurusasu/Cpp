#pragma once

//クラス名 熱伝導解析
//　　データメンバ：ループ回数
//　　　　　　　　　分割数
//　　メンバ関数　：コンストラクタ
//　　　　　　　　　初期設定
//                  計算
//　　　　　　　　　ファイルへの書き出し

class Netudendou
{
public:
	Netudendou();
	~Netudendou();

	//prinvate変数に値を代入
	void PrivateFromUser(); 
	void PrivateFromSet(double length, 
		                double T0, 
		                double TH, 
		                double TL, 
		                double LOOP);
	//初期化を行う関数
	void init();
	//実際に計算を行う関数
	void func();          
	//ファイルへの書き込みを行う関数
	void write(char System);

	//値を返す関数
	int get_M()const { return M; }
	double* get_pointer_X()const { return X_point; }
	double* get_pointer_T()const { return T_point; }


private:
	FILE *fp;
	int M; 
	int prLOOP;
	double* X_point;
	double* T_point;
	double* Told_point;

	double prLength;
	double prT0;
	double prTH;
	double prTL;
};