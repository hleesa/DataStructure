#include <iostream>

using namespace std;

void mySwap(int* lhs, int* rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void mySwapRef(int& lhs, int& rhs){
    int temp = rhs;
    rhs = lhs;
    lhs = temp;
}

int main() {
    {
        int a = 3;
        int b = 2;

        cout << a << ' ' << b << '\n';

//        int temp = a;
//        a = b;
//        b = temp;
//        mySwap(&a, &b);
        mySwapRef(a, b);


        cout << a << ' ' << b << '\n';
    }

    return 0;
}

/*
 * 1. swap 함수를 구현 할때, pointer 방식만 생각함.
 *  reference 방식을 생각 못함.
 *
 *  2. 정렬을 오름차순 한 방식만 생각함.
 *   내림차순 정렬도 있다.
 *
 */