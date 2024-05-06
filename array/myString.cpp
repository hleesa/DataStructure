#include <cstring>
#include <new>
#include <iostream>
#include "myString.hpp"

myString::myString() : size_(0), str_(nullptr) {
}

myString::myString(const char* cStr) : size_(strlen(cStr)) {
    try {
        str_ = new char[size_];
        strcpy(str_, cStr);
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    memmove(str_, cStr, size_);
}

myString::myString(const myString& string) : size_(string.size_) {
    try {
        str_ = new char[size_];
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    memmove(str_, string.str_, size_);
}

myString::~myString() {
    if (str_ != nullptr) {
        delete[] str_;
    }
}

bool myString::isEmpty() {
    return size_ == 0;
}

bool myString::isEqual(const myString& string) {
    if (size_ != string.size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (str_[i] != string.str_[i]) {
            return false;
        }
    }
    return true;
}

int myString::length() {
    return size_;
}

void myString::resize(int newSize) {
    if (newSize == size_) {
        return;
    }

    char* newStr = nullptr;

    try {
        newStr = new char[newSize];
        bzero(newStr, newSize);
        memmove(newStr, str_, newSize);
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    delete[] str_;
    str_ = newStr;
    size_ = newSize;
}

myString myString::substr(int begin, int num) {
    assert(begin +num -1 < size_);

    char* subStr = nullptr;

    try {
        subStr = new char[num];
        memmove(subStr, str_ + begin, num);
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    return myString(subStr);
}

myString myString::concat(myString appStr) {
    int concatSize = size_ + appStr.size_;
    char* concatStr = nullptr;

    try {
        concatStr = new char[concatSize];
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    memmove(concatStr, str_, size_);
    memmove(concatStr + size_, appStr.str_, appStr.size_);
    return myString(concatStr);
}

myString myString::insert(myString t, int begin) {
    int insertSize = size_ + t.size_;
    char* insertStr = nullptr;

    try {
        insertStr = new char[insertSize + 1];
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
    strncpy(insertStr, str_, begin);
    strcpy(insertStr + begin, t.str_);
    strcpy(insertStr + begin + t.size_, str_ + begin);
    return myString(insertStr);
}

int myString::find(myString pat) {
    for (int i = 0; i + pat.size_ <= size_; ++i) {
        bool same = true;
        for (int j = 0; j < pat.size_; ++j) {
            if (str_[i + j] != pat.str_[j]) {
                same = false;
                break;
            }
        }
        if (same) {
            return i;
        }
    }
    return -1;
}

void myString::print() {
    std::cout << str_ << '\n';
}