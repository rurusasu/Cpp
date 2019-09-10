#include "stdafx.h"
#include "Netudendou.h"

//�R���X�g���N�^
Netudendou::Netudendou()
{
	fopen_s(&fp, "result.csv","w");
	std::cout << "Netudendou�I�u�W�F�N�g����������܂����B" << std::endl;
}

//�f�X�g���N�^
Netudendou::~Netudendou()
{
	fclose(fp);
	std::cout << "Netudendou�̃C���X�^���X�����ł��܂����B" << std::endl;
}

void Netudendou::PrivateFromUser()
{
	char usChar;
	while (true) {
		std::cout << "�_�̏���������ݒ肵�܂��B" << std::endl;

		//�_�̒���
		std::cout << "�_�̒���[m]�F";  std::cin >> prLength;

		//���̓G���[���N�����ꍇ
		while (!std::cin && !prLength > 0) {
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "�ē��͂��Ă��������B" << std::endl;
			std::cout << "�_�̒���[m]�F";
			std::cin >> prLength;
		}

		//�_�̏������x
		std::cout << "�_�̏������x[��]�F";
		std::cin >> prT0;

		//���̓G���[���N�����ꍇ
		while (!std::cin) {
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "�ē��͂��Ă��������B" << std::endl;
			std::cout << "�_�̏������x[��]�F";
			std::cin >> prT0;
		}

		//�������̋��E���x
		std::cout << "�������̋��E���x[��]�F";
		std::cin >> prTH;

		//���̓G���[���N�����ꍇ
		while (!std::cin) {
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "�ē��͂��Ă��������B" << std::endl;
			std::cout << "�������̋��E���x[��]�F";
			std::cin >> prTH;
		}

		//�ቷ���̋��E���x
		std::cout << "�ቷ���̋��E���x[��]�F";
		std::cin >> prTL;

		//���̓G���[���N�����ꍇ
		while (!std::cin) {
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "�ē��͂��Ă��������B" << std::endl;
			std::cout << "�ቷ���̋��E���x[��]�F";
			std::cin >> prTL;
		}

		//���͌��ʂ̏o��
		std::cout << "���͌��ʂ�\n"
			<< "�_�̒���[m]�F" << prLength << "\n"
			<< "�_�̏������x�F" << prT0 << "\n"
			<< "�������̋��E���x�F" << prTH << "\n"
			<< "�ቷ���̋��E���x�F" << prTL << "\n"
			<< "�ł����ł����B[Y/N]"
			<< std::endl;
		std::cin >> usChar;

		while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
		{
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "[Y/N]�œ��͂��Ă��������B" << std::endl;
			std::cin >> usChar;
		}

		if ((usChar == 'y') || (usChar == 'Y')) break;
		else std::cout << "�ē��͂��n�߂܂��B" << std::endl;
	}

	while (true)
	{
		std::cout << "���s�񐔂���͂��Ă��������F";
		std::cin >> prLOOP;

		//���̓G���[���N�����ꍇ
		while (!std::cin) {
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "�ē��͂��Ă��������B" << std::endl;
			std::cout << "�ቷ���̋��E���x[��]�F";
			std::cin >> prLOOP;
		}

		//���͌��ʂ̏o��
		std::cout << "���s�񐔂́F\n" << prLOOP << "��ł����ł����B[Y/N]" << std::endl;
		std::cin >> usChar;

		while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
		{
			//�G���[������
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			//�ē���
			std::cout << "[Y/N]�œ��͂��Ă��������B" << std::endl;
			std::cin >> usChar;
		}

		if ((usChar == 'y') || (usChar == 'Y')) return;
		else std::cout << "�ē��͂��n�߂܂��B" << std::endl;
	}
}

void Netudendou::PrivateFromSet(double length, double T0, double TH, double TL,double LOOP) {
	char usChar;
	prLength = length;
	prT0 = T0;
	prTH = TH;
	prTL = TL;
	prLOOP = LOOP;

	//���͌��ʂ̏o��
	std::cout << "�����ݒ��\n"
		<< "�_�̒���[m]�F"      << prLength << "\n"
		<< "�_�̏������x�F"     << prT0 << "\n"
		<< "�������̋��E���x�F" << prTH << "\n"
		<< "�ቷ���̋��E���x�F" << prTL << "\n"
		<<"���s�񐔁F"          <<prLOOP<<"\n"
		<< "�ł��B�����ł���[Y/N]"
		<< std::endl;
	std::cin >> usChar;

	while (((!usChar == 'y') && (!usChar == 'Y')) || ((!usChar == 'n') && (!usChar == 'N')))
	{
		//�G���[������
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		//�ē���
		std::cout << "[Y/N]�œ��͂��Ă��������B" << std::endl;
		std::cin >> usChar;
	}

	if ((usChar == 'y') || (usChar == 'Y')) return;
	else if ((usChar == 'n') || (usChar == 'N')) PrivateFromUser();
}


void Netudendou::init()
{
	double dx;

	//���ׂĂ̔z��̏�����
	for (int i = 0; i <= M; i++) {
		X_point[i] = 0.0;
		T_point[i] = 0.0;
		Told_point[i] = 0.0;
	}

	//��Ԋi�q����шʒu���
	dx = prLength / (float)(M);
	X_point[0] = 0.0;
	for (int i = 1; i <= M; i++) X_point[i] = 0.0 + dx * (float)i;

	write('X'); //X�̒l���t�@�C���֏�������

	//���E���x�̏��
	prT0 = prT0 + 273.15; //�_�̏������x[K]
	prTH = prTH + 273.15; //�������̋��E���x[K]
	prTL = prTL + 273.15; //�ቷ���̋��E���x[K]
	T_point[0] = prTH;
	T_point[prLOOP] = prTL;

	//���������i�������x�j
	for (int i = 1; i == prLOOP; i++) T_point[i] = prT0;

	write('T'); //T�̒l���t�@�C���֏�������
}

void func()
{
	for (int j = 1; j < ; j++) {

	}
}

//�t�@�C���ւ̏������݂��s���֐�
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