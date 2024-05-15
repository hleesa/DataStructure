#include "SparsePolynomial.hpp"

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

SparsePolynomial::SparsePolynomial(const SparsePolynomial& other) : capacity_(other.capacity_),
                                                                    num_terms_(other.num_terms_),
                                                                    terms_(new Term[other.num_terms_]) {
    memmove(terms_, other.terms_, sizeof(Term) * num_terms_);
}

SparsePolynomial::~SparsePolynomial() {
    if (terms_) {
        delete[] terms_;
    }
}

void SparsePolynomial::NewTerm(float coef, int exp) {
    if (coef == 0.0f) return;

    if (num_terms_ >= capacity_) {
        // capacity 증가 (num_terms는 일단 고정)
        capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; // 2배씩 증가
        Term* new_term = new Term[capacity_];

        // 원래 가지고 있던 데이터 복사
        memcpy(new_term, terms_, sizeof(Term) * num_terms_);

        // 메모리 교체
        if (terms_) delete[] terms_;
        terms_ = new_term;
    }
    terms_[num_terms_].coef = coef;
    terms_[num_terms_].exp = exp;
    int i = num_terms_;
    while (i >= 1 && terms_[i - 1].exp > terms_[i].exp) {
        swap(terms_[i - 1].exp, terms_[i].exp);
        swap(terms_[i - 1].coef, terms_[i].coef);
        --i;
    }
    num_terms_++;
}

float SparsePolynomial::Eval(float x) {
    float result = 0.0f;

    for (int i = 0; i < num_terms_; ++i) {
        result += terms_[i].coef * pow(x, terms_[i].exp);
    }
    return result;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly) {
    // this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
    // 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

    SparsePolynomial result;

    int ti = 0, pi = 0;

    while (ti < num_terms_ && pi < poly.num_terms_) {
        if (terms_[ti].exp < poly.terms_[pi].exp) {
            result.NewTerm(terms_[ti].coef, terms_[ti].exp);
            ++ti;
        }
        else if (terms_[ti].exp == poly.terms_[pi].exp) {
            if(terms_[ti].coef + poly.terms_[pi].coef != 0.0f) {
                result.NewTerm(terms_[ti].coef + poly.terms_[pi].coef, terms_[ti].exp);
            }
            ++ti;
            ++pi;
        }
        else if (poly.terms_[ti].exp < terms_[pi].exp) {
            result.NewTerm(poly.terms_[pi].coef, poly.terms_[pi].exp);
            ++pi;
        }
    }
    while (ti < num_terms_) {
        result.NewTerm(terms_[ti].coef, terms_[ti].exp);
        ++ti;
    }
    while (pi < poly.num_terms_) {
        result.NewTerm(poly.terms_[pi].coef, poly.terms_[pi].exp);
        ++pi;
    }

    return result;
}

void SparsePolynomial::Print() {
    bool is_first = true; // 더하기 출력시 확인용

    for (int i = 0; i < num_terms_; i++) {
        // 0이 아닌 항들만 골라서 출력할 필요가 없음

        if (!is_first)
            cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

        cout << terms_[i].coef;

        if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

        is_first = false;
    }

    cout << endl;
}
