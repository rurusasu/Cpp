#include <stdio.h>
#include <stdarg.h> //va_start, va_arg, ar_end�ɕK�v�B
#include <string>   //strlen�ɕK�v�B

using namespace std;

class CManiac {
public:
    //�P�����Z�q + ���`����B
    int operator+() {
        return 1;
    }
};

class CManiac2 {
    //���̗�ł́A���̍s�͂Ȃ��Ă����삷��B
    friend int operator-(CManiac2&);
};
//CManiac2�ɑ΂���P�����Z�q - ���O���[�o���֐��Ƃ��Ē�`����B
int operator-(CManiac2& rmaniac2) {
    return 2;
}

//()�A�֐��Ăяo�����Z�q�A�֐��I�u�W�F�N�g
class CManiac3 {
public:
    int operator()(int iValue3){
        return 3 * iValue3;
    }
};

//()�A�����̈��������֐��Ăяo�����Z�q�A�֐��I�u�W�F�N�g
class CManiac4 {
public:
    int operator()(int iValue, float fValue, ...) {
        va_list valist;

        //�ϒ�������1�̕ϐ��ɂ܂Ƃ߂�B
        va_start(valist, fValue);
        char* pcText = va_arg(valist, char*);
        va_end(valist);
        return iValue + int(fValue) + strlen(pcText); //strlen�͕�����̒������o�C�g���ŕԂ��B
    }
};

//int�^�ɕϊ�����L���X�g���Z�q
class CManiac5 {
public:
    operator int() {
        return 1;
    }
};


int main() {
    CManiac maniac1;                 //�N���X�I�u�W�F�N�gmaniac���쐬����B
    int iValue = +maniac1;           //�P�����Z�q + ��maniac�ɓK�p����B
    printf("iValue = %d\n", iValue); //������1�ɂȂ�B

    //int iValue = maniac1 + ;  �P�����Z�q + �͑O�ɂ�������Ȃ��B

    CManiac2 maniac2;                  //�N���X�I�u�W�F�N�gmaniac2���쐬����B
    int iValue2 = -maniac2;            //�P�����Z�q - ��maniac�ɓK�p����B
    printf("iValue2 = %d\n", iValue2); //������2�ɂȂ�B

    //int iValue2 = maniac2 - ;  �P�����Z�q - �͑O�ɂ�������Ȃ��B

    CManiac3 maniac3;                  //�N���X�I�u�W�F�N�gmaniac3���쐬����B
    int iValue3 = maniac3(1);          //�֐��Ăяo�����Z�q () ��maniac3�K�p����B
    printf("iValue3 = %d\n", iValue3); //������3�ɂȂ�B

    //int iValue4 = (1)maniac3;  �֐��Ăяo�����Z�q () �͌��ɂ�������Ȃ��B

    CManiac4 maniac4;                         //�N���X�I�u�W�F�N�gmaniac4���쐬����B
    int iValue4 = maniac4(1, 2.3f, "maniac"); //�����̈��������֐��Ăяo�����Z�q () ��maniac4�ɓK�p����B
    printf("iValue4 = %d\n", iValue);          //������9�ɂȂ�B

    CManiac5 maniac5;                                         //�N���X�I�u�W�F�N�gmaniac5���쐬����B
    int iValue5 = (int)maniac5;                               //�L���X�g���Z�q (int) ��maniac5�ɓK�p����B
    int iValue6 = int(maniac5);                               //��L�ƈقȂ�`�ŁA�L���X�g���Z�q int() ��maniac5�ɓK�p����B
    printf("iValue5 = %d, iValue6 = %d\n", iValue5, iValue6); //�����Ƃ�������1�ɂȂ�B


    return 0;
}