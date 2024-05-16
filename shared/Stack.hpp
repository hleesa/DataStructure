#include <cassert>
#include <cstring>
#include <iostream>

template<typename T>
class Stack
{
public:
    Stack(int capacity = 1){
        assert(capacity > 0);
        resize(capacity);
    }

    ~Stack() {
        if (stack_) {
            delete[] stack_;
        }
    }

    void resize(int newCapacity){
        T* newStack = new T[newCapacity];
        memcpy(newStack, stack_, sizeof(T) * size());
        if (stack_) {
            delete[] stack_;
        }
        stack_ = newStack;
        capacity_ = newCapacity;
    }

    bool isEmpty() const {
        return size() == 0;
    }

    int size() const{
        return top_ + 1;
    }

    void print(){
        using namespace std;

        for (int i = 0; i < size(); ++i) {
            cout << stack_[i] << " ";
        }
        cout << '\n';
    }

    T& top() const {
        assert(!isEmpty());

        return stack_[top_];
    }

    void push(const T& item){
        if (size() == capacity_) {
            resize(capacity_ * 2);
        }
        ++top_;
        stack_[top_] = item;
    }

    void pop(){
        assert(!isEmpty());

        --top_;
    }



private:
    T* stack_ = nullptr;
    int top_ = -1;
    int capacity_ = 0;
};
