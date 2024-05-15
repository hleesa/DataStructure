#include <cstring>
#include <algorithm>
#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity) : num_rows_(num_rows), num_cols_(num_cols),
                                                                       capacity_(capacity), num_terms_(0),
                                                                       terms_(new MatrixTerm[capacity]) {
    for (int i = 0; i < capacity_; ++i) {
        terms_[i].value = 0.0f;
    }
}

SparseMatrix::SparseMatrix(const SparseMatrix& other) : num_rows_(other.num_rows_), num_cols_(other.num_cols_),
                                                        capacity_(other.capacity_), num_terms_(other.num_terms_),
                                                        terms_(new MatrixTerm[other.capacity_]) {
    memmove(terms_, other.terms_, sizeof(MatrixTerm) * capacity_);
}

SparseMatrix::~SparseMatrix() {
    if (terms_) {
        delete[] terms_;
    }
}

bool SparseMatrix::compare(MatrixTerm* lhs, MatrixTerm* rhs) {
    if (rhs->row < lhs->row) {
        return true;
    }
    else if (rhs->row == lhs->row) {
        if (rhs->col < lhs->col) {
            return true;
        }
        else if (rhs->col == lhs->col) {
            return lhs->value < rhs->value;
        }
    }
    return false;
}

void SparseMatrix::setValue(int row, int col, float value) {
    if (value == 0.0f) {
        return;
    }

    terms_[num_terms_++] = {row, col, value};
    for (int i = num_terms_ - 1; i > 0; --i) {
        if (compare(&terms_[i - 1], &terms_[i])) {
            swap(terms_[i - 1], terms_[i]);
        }
        else {
            break;
        }
    }
}

float SparseMatrix::getValue(int row, int col) const {
    for (int i = 0; i < num_terms_; ++i) {
        if (terms_[i].row == row && terms_[i].col == col) {
            return terms_[i].value;
        }
    }
    return 0.0f;
}

SparseMatrix SparseMatrix::transpose() {
    SparseMatrix result(num_cols_, num_rows_, capacity_);

    for (int i = 0; i < num_terms_; ++i) {
        result.setValue(terms_[i].col, terms_[i].row, terms_[i].value);
    }

    return result;
}

void SparseMatrix::printTerms() {
    for (int i = 0; i < num_terms_; i++)
        cout << "(" << terms_[i].row
             << ", " << terms_[i].col
             << ", " << terms_[i].value
             << ")\n";
}

void SparseMatrix::print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++)
            cout << getValue(r, c) << " ";
        cout << '\n';
    }
}

