#pragma once

//�N���X�� �M�`�����
//�@�@�f�[�^�����o�F���[�v��
//�@�@�@�@�@�@�@�@�@������
//�@�@�����o�֐��@�F�R���X�g���N�^
//�@�@�@�@�@�@�@�@�@�����ݒ�
//                  �v�Z
//�@�@�@�@�@�@�@�@�@�t�@�C���ւ̏����o��

class Netudendou
{
public:
	Netudendou();
	~Netudendou();

	//prinvate�ϐ��ɒl����
	void PrivateFromUser(); 
	void PrivateFromSet(double length, 
		                double T0, 
		                double TH, 
		                double TL, 
		                double LOOP);
	//���������s���֐�
	void init();
	//���ۂɌv�Z���s���֐�
	void func();          
	//�t�@�C���ւ̏������݂��s���֐�
	void write(char System);

	//�l��Ԃ��֐�
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