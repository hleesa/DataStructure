#include <iostream>
#include <cassert>
#include "Array2D.hpp"

using namespace std;

Array2D::Array2D(int numRow, int numCol) : numRow(numRow), numCol(numCol) {
    arrays = new float* [numRow];
    for (int r = 0; r < numRow; ++r) {
        arrays[r] = new float[numCol];
    }

    for (int r = 0; r < numRow; ++r) {
        for (int c = 0; c < numCol; ++c) {
            arrays[r][c] = 0.0f;
        }
    }
}

Array2D::Array2D(const Array2D& other) : numRow(other.numRow), numCol(other.numCol) {
    arrays = new float* [numRow];
    for (int r = 0; r < numRow; ++r) {
        arrays[r] = new float[numCol];
        arrays[r] = other.arrays[r];
    }
}

Array2D::~Array2D() {
    if (arrays) {
        for (int r = 0; r < numRow; ++r) {
            if(arrays[r]) {
                delete[] arrays[r];
            }
        }
        delete[] arrays;
    }
}

void Array2D::setValue(int row, int col, float value) {
    arrays[row][col] = value;
}

float Array2D::getValue(int row, int col) const {
    return arrays[row][col];
}

Array2D Array2D::transpose() {
    Array2D result(numCol, numRow);

    for (int r = 0; r < numRow; ++r) {
        for (int c = 0; c < numCol; ++c) {
            result.setValue(c, r, getValue(r, c));
        }
    }

    return result;
}

Array2D Array2D::add(const Array2D& other) {
    assert(other.numRow == numRow);
    assert(other.numCol == numCol);

    Array2D result(numRow, numCol);

    for (int r = 0; r < numRow; ++r) {
        for (int c = 0; c < numCol; ++c) {
            result.setValue(r, c, getValue(r, c) + other.getValue(r, c));
        }
    }

    return result;
}

void Array2D::print() {
    for (int r = 0; r < numRow; ++r) {
        for (int c = 0; c < numCol; ++c) {
            cout << getValue(r, c) << " ";
        }
        cout << '\n';
    }
}