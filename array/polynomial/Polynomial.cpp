
#include "Polynomial.hpp"

#include <cassert>
#include <iostream>
#include <math.h> // std::powf()

using namespace std;

Polynomial::Polynomial(int max_degree) // 편의상 기본값 사용
{
    assert(max_degree > 0);

    capacity_ = max_degree + 1;

    coeffs_ = new float[capacity_];

    for (int i = 0; i < capacity_; i++)
        coeffs_[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
    capacity_ = poly.capacity_;
    coeffs_ = new float[capacity_];
    for (int i = 0; i < capacity_; i++)
        coeffs_[i] = poly.coeffs_[i];
}

Polynomial::~Polynomial()
{
    if (coeffs_)
        delete[] coeffs_;
}

int Polynomial::maxDegree()
{
    return this->capacity_ - 1;
}

void Polynomial::newTerm(const float coef, const int exp)
{
    assert(exp < capacity_);

    coeffs_[exp] = coef;
}

Polynomial Polynomial::add(const Polynomial& poly)
{
    assert(poly.capacity_ == capacity_); // 문제를 단순화하기 위한 가정

    Polynomial temp(maxDegree());

    for (int i = 0; i < capacity_; ++i) {
        temp.coeffs_[i] = coeffs_[i] + poly.coeffs_[i];
    }

    return temp;
}

Polynomial Polynomial::mult(const Polynomial& poly)
{
    assert(poly.capacity_ == this->capacity_); // 문제를 단순화하기 위한 가정

    Polynomial temp(maxDegree());

    for (int i = 0; i < capacity_; ++i) {
        for (int j = 0; j < poly.capacity_; ++j) {
            if (coeffs_[i] == 0.0f || poly.coeffs_[j] == 0.0f) {
                continue;
            }
            if (i + j >= capacity_) {
                continue;
            }
            temp.coeffs_[i + j] += coeffs_[i] * poly.coeffs_[j];
        }
    }
    return temp;
}

float Polynomial::eval(float x)
{
    float temp = 0.0f;

    for (int i = 0; i < capacity_; ++i) {
        if (coeffs_[i] == 0.0f) {
            continue;
        }
        temp += coeffs_[i] * powf(x, float(i));
    }
    return temp;
}

void Polynomial::print()
{
    bool is_first = true; // 더하기 출력시 확인용

    for (int i = 0; i < capacity_; i++)
    {
        if (coeffs_[i] != 0.0f) // 주의: 0이 아닌 항들만 출력
        {
            if (!is_first)
                cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

            cout << coeffs_[i];

            if (i != 0) cout << "*" << "x^" << i;

            is_first = false;
        }
    }

    cout << endl;
}