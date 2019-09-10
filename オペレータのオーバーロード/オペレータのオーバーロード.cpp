#include <stdio.h>
#include <stdarg.h> //va_start, va_arg, ar_endに必要。
#include <string>   //strlenに必要。

using namespace std;

class CManiac {
public:
    //単項演算子 + を定義する。
    int operator+() {
        return 1;
    }
};

class CManiac2 {
    //この例では、この行はなくても動作する。
    friend int operator-(CManiac2&);
};
//CManiac2に対する単項演算子 - をグローバル関数として定義する。
int operator-(CManiac2& rmaniac2) {
    return 2;
}

//()、関数呼び出し演算子、関数オブジェクト
class CManiac3 {
public:
    int operator()(int iValue3){
        return 3 * iValue3;
    }
};

//()、複数の引数を取る関数呼び出し演算子、関数オブジェクト
class CManiac4 {
public:
    int operator()(int iValue, float fValue, ...) {
        va_list valist;

        //可変長引数を1個の変数にまとめる。
        va_start(valist, fValue);
        char* pcText = va_arg(valist, char*);
        va_end(valist);
        return iValue + int(fValue) + strlen(pcText); //strlenは文字列の長さをバイト数で返す。
    }
};

//int型に変換するキャスト演算子
class CManiac5 {
public:
    operator int() {
        return 1;
    }
};


int main() {
    CManiac maniac1;                 //クラスオブジェクトmaniacを作成する。
    int iValue = +maniac1;           //単項演算子 + をmaniacに適用する。
    printf("iValue = %d\n", iValue); //答えは1になる。

    //int iValue = maniac1 + ;  単項演算子 + は前にしかつけれない。

    CManiac2 maniac2;                  //クラスオブジェクトmaniac2を作成する。
    int iValue2 = -maniac2;            //単項演算子 - をmaniacに適用する。
    printf("iValue2 = %d\n", iValue2); //答えは2になる。

    //int iValue2 = maniac2 - ;  単項演算子 - は前にしかつけれない。

    CManiac3 maniac3;                  //クラスオブジェクトmaniac3を作成する。
    int iValue3 = maniac3(1);          //関数呼び出し演算子 () をmaniac3適用する。
    printf("iValue3 = %d\n", iValue3); //答えは3になる。

    //int iValue4 = (1)maniac3;  関数呼び出し演算子 () は後ろにしかつけれない。

    CManiac4 maniac4;                         //クラスオブジェクトmaniac4を作成する。
    int iValue4 = maniac4(1, 2.3f, "maniac"); //複数の引数を持つ関数呼び出し演算子 () をmaniac4に適用する。
    printf("iValue4 = %d\n", iValue);          //答えは9になる。

    CManiac5 maniac5;                                         //クラスオブジェクトmaniac5を作成する。
    int iValue5 = (int)maniac5;                               //キャスト演算子 (int) をmaniac5に適用する。
    int iValue6 = int(maniac5);                               //上記と異なる形で、キャスト演算子 int() をmaniac5に適用する。
    printf("iValue5 = %d, iValue6 = %d\n", iValue5, iValue6); //両方とも答えは1になる。


    return 0;
}