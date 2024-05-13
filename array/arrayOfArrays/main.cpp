#include "Array2D.hpp"

#include <iostream>


int main()
{
    using namespace std;

    Array2D m1(3, 4);
    m1.setValue(0, 0, 1.0f);
    m1.setValue(0, 1, 2.0f);
    m1.setValue(0, 2, 3.0f);
    m1.setValue(1, 0, 0.0f);
    m1.setValue(1, 1, 4.0f);
    m1.setValue(1, 2, 5.0f);
    m1.setValue(2, 3, 7.0f);

    m1.print();

    cout << endl;

    Array2D add = m1.add(m1); // 자기 자신과 더하기
    add.print();

    cout << endl;

    Array2D tr = m1.transpose(); // 전치행렬
    tr.print();

    return 0;
}

