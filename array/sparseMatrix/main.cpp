#include <iostream>

#include "SparseMatrix.hpp"

int main()
{
    using namespace std;

    SparseMatrix m1(4, 6, 6); // 4 by 6 matrix, Non-zero term 8개

    // 정렬되지 않은 순서로 추가
    m1.setValue(2, 3, 5.0f);
    m1.setValue(0, 5, 2.0f);
    m1.setValue(1, 1, 1.0f);
    m1.setValue(0, 0, 1.0f);
    m1.setValue(0, 3, 7.0f);
    m1.setValue(1, 2, 3.0f);

    // m1.setValue(2, 3, 4.0f); // <- 덮어쓰는 경우

    m1.printTerms();
    m1.print();

    cout << endl;

    SparseMatrix tr = m1.transpose(); // 전치행렬

    tr.printTerms();
    tr.print();

    return 0;
}

