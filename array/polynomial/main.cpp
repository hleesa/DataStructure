#include "Polynomial.hpp"

#include <iostream>

int main()
{
    using namespace std;

    Polynomial p1; // max_degree는 기본값으로 설정

    p1.newTerm(1, 0);		// 1 * x^0 = 1
    p1.newTerm(1.5f, 1);	// 1.5 * x^1
    p1.newTerm(2, 2);		// 2 * x^2

    p1.print(); // 1 + 1.5*x^1 + 2*x^2

    cout << p1.eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
    cout << p1.eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
    cout << p1.eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

    cout << endl;

    Polynomial p2;

    p2.newTerm(1, 1);
    p2.newTerm(3, 2);

    p2.print(); // 1*x^1 + 3*x^2

    cout << endl;

    cout << "Add()" << endl;

    Polynomial psum = p1.add(p2);
    psum.print(); // 1 + 2.5*x^1 + 5*x^2

    cout << endl;

    cout << "Mult()" << endl;

    p1.print();	  // 1 + 1.5*x^1 + 2*x^2
    p2.print();	  // 1*x^1 + 3*x^2

    Polynomial pmul = p1.mult(p2);
    pmul.print(); // 1*x^1 + 4.5*x^2 + 6.5*x^3 + 6*x^4

    return 0;
}

