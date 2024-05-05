#include <cstring>
#include <new>
#include <iostream>
#include "myString.hpp"

myString::myString() {
    size_ = 0;
    str_ = nullptr;
}

myString::myString(const char* cStr) {
    size_ = strlen(cStr);

    try{
        char* str_ = new char[size_];
        strcpy(str_, cStr);
    } catch (std::bad_alloc& e) {
        std::cerr << "memory allocation failed: " << e.what() << '\n';
    }
}

myString::myString(const myString& string) : size_(string.size_) {
    strcpy(str_, string.str_);
}

myString::~myString(){
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