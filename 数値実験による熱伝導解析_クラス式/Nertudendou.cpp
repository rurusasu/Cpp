#include "stdafx.h"
#include "Netudendou.h"

//コンストラクタ
Netudendou::Netudendou()
{
	fopen_s(&fp, "result.csv","w");
	std::cout << "Netudendouオブジェクトが生成されました。" << std::endl;
}

//デストラクタ
Netudendou::~Netudendou()
{
	fclose(fp);
	std::cout << "Netudendouのインスタンスが消滅しました。" << std::endl;
}

void Netudendou::PrivateFromUser()
{
	char usChar;
	while (true) {
		std::cout << "棒の初期条件を設定します。" << std::endl;

		//棒の長さ
		std::cout << "棒の長さ[m]：";  std::cin >> prLength;

		//入力エラーが起きた場合
		while (!std::cin && !prLength > 0) {
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "再入力してください。" << std::endl;
			std::cout << "棒の長さ[m]：";
			std::cin >> prLength;
		}

		//棒の初期温度
		std::cout << "棒の初期温度[℃]：";
		std::cin >> prT0;

		//入力エラーが起きた場合
		while (!std::cin) {
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "再入力してください。" << std::endl;
			std::cout << "棒の初期温度[℃]：";
			std::cin >> prT0;
		}

		//高温側の境界温度
		std::cout << "高温側の境界温度[℃]：";
		std::cin >> prTH;

		//入力エラーが起きた場合
		while (!std::cin) {
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "再入力してください。" << std::endl;
			std::cout << "高温側の境界温度[℃]：";
			std::cin >> prTH;
		}

		//低温側の境界温度
		std::cout << "低温側の境界温度[℃]：";
		std::cin >> prTL;

		//入力エラーが起きた場合
		while (!std::cin) {
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "再入力してください。" << std::endl;
			std::cout << "低温側の境界温度[℃]：";
			std::cin >> prTL;
		}

		//入力結果の出力
		std::cout << "入力結果は\n"
			<< "棒の長さ[m]：" << prLength << "\n"
			<< "棒の初期温度：" << prT0 << "\n"
			<< "高温側の境界温度：" << prTH << "\n"
			<< "低温側の境界温度：" << prTL << "\n"
			<< "でいいですか。[Y/N]"
			<< std::endl;
		std::cin >> usChar;

		while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
		{
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "[Y/N]で入力してください。" << std::endl;
			std::cin >> usChar;
		}

		if ((usChar == 'y') || (usChar == 'Y')) break;
		else std::cout << "再入力を始めます。" << std::endl;
	}

	while (true)
	{
		std::cout << "試行回数を入力してください：";
		std::cin >> prLOOP;

		//入力エラーが起きた場合
		while (!std::cin) {
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "再入力してください。" << std::endl;
			std::cout << "低温側の境界温度[℃]：";
			std::cin >> prLOOP;
		}

		//入力結果の出力
		std::cout << "試行回数は：\n" << prLOOP << "回でいいですか。[Y/N]" << std::endl;
		std::cin >> usChar;

		while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
		{
			//エラーを解除
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//再入力
			std::cout << "[Y/N]で入力してください。" << std::endl;
			std::cin >> usChar;
		}

		if ((usChar == 'y') || (usChar == 'Y')) return;
		else std::cout << "再入力を始めます。" << std::endl;
	}
}

void Netudendou::PrivateFromSet(double length, double T0, double TH, double TL,double LOOP) {
	char usChar;
	prLength = length;
	prT0 = T0;
	prTH = TH;
	prTL = TL;
	prLOOP = LOOP;

	//入力結果の出力
	std::cout << "初期設定は\n"
		<< "棒の長さ[m]："      << prLength << "\n"
		<< "棒の初期温度："     << prT0 << "\n"
		<< "高温側の境界温度：" << prTH << "\n"
		<< "低温側の境界温度：" << prTL << "\n"
		<<"試行回数："          <<prLOOP<<"\n"
		<< "です。いいですか[Y/N]"
		<< std::endl;
	std::cin >> usChar;

	while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
	{
		//エラーを解除
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		//再入力
		std::cout << "[Y/N]で入力してください。" << std::endl;
		std::cin >> usChar;
	}

	if ((usChar == 'y') || (usChar == 'Y')) return;
	else if ((usChar == 'n') || (usChar == 'N')) PrivateFromUser();
}


void Netudendou::init()
{
	double dx;

	//すべての配列の初期化
	for (int i = 0; i <= M; i++) {
		X_point[i] = 0.0;
		T_point[i] = 0.0;
		Told_point[i] = 0.0;
	}

	//空間格子および位置情報
	dx = prLength / (float)(M);
	X_point[0] = 0.0;
	for (int i = 1; i <= M; i++) X_point[i] = 0.0 + dx * (float)i;

	write('X'); //Xの値をファイルへ書き込む

	//境界温度の情報
	prT0 = prT0 + 273.15; //棒の初期温度[K]
	prTH = prTH + 273.15; //高温側の境界温度[K]
	prTL = prTL + 273.15; //低温側の境界温度[K]
	T_point[0] = prTH;
	T_point[prLOOP] = prTL;

	//初期条件（初期温度）
	for (int i = 1; i == prLOOP; i++) T_point[i] = prT0;

	write('T'); //Tの値をファイルへ書き込む
}

void func()
{
	for (int j = 1; j < ; j++) {

	}
}

//ファイルへの書き込みを行う関数
void Netudendou::write(char System)
{
	int M = get_M();
	double* xp = get_pointer_X();
	double* tp = get_pointer_T();

	for (int i = 0; i <= M; i++) {
		if (System == 'X') fprintf(fp, ",%f,", xp[i]);
		if (System == 'T') fprintf(fp, ",%f,", tp[i]);
	}
	fprintf(fp, "\n");
}