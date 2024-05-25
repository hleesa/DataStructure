#pragma once

#include "Queue.hpp"

template<typename T>
class Deque : public Queue<T>
{
    typedef Queue<T> base;

public:
    Deque(int capacity) : Queue<T>(capacity) {
    }

    T& front(){
        return base::front();
    }

    T& back(){
        return base::rear();
    }

    void pushFront(const T& item){
        if (base::isFull()) {
            base::resize();
        }

        base::queue_[base::front_] = item;
        base::front_ = (base::front_ + (base::capacity_ - 1)) % base::capacity_;
    }

    void pushBack(const T& item){
        base::enqueue(item);
    }

    void popFront(){
        base::dequeue();
    }

    void popBack(){
        assert(!base::isEmpty());

        base::rear_ = (base::rear_ + (base::capacity_ - 1)) % base::capacity_;
    }

private:


};
