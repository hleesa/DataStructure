#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class Queue{
public:
    Queue(int capacity = 2){
        assert(capacity > 0);

        capacity_ = capacity;
        queue_ = new T[capacity_];
        front_ = rear_ = 0;
    }

    ~Queue(){
        if(queue_)
            delete[] queue_;
    }

    bool isEmpty() const {
        return front_ == rear_;
    }

    bool isFull() const {
        return (rear_ + 1) % capacity_ == front_;
    }

    T& front() const{
        assert(!isEmpty());

        return queue_[(front_ + 1) % capacity_];
    }

    T& rear() const{
        assert(!isEmpty());

        return queue_[(rear_ + 1) % capacity_];
    }

    int size() const{
        int size = abs(rear_ - front_);

        if (rear_ < front_) {
            size = capacity_ - size;
        }

        return size;
    }

    void resize(){
        T* newQueue = new T[capacity_ * 2];

        if (front_ < rear_) {
            memcpy(newQueue + front_ + 1, queue_ + front_ + 1, sizeof(T) * size());
        }
        else if (rear_ < front_) {
            memcpy(newQueue + 1, queue_ + front_ + 1, sizeof(T) * (capacity_ - (front_ + 1)));
            memcpy(newQueue + 1 + capacity_ - (front_ + 1), queue_, sizeof(T) * (rear_ + 1));
            front_ = 0;
            rear_ = capacity_ - 1;
        }

        if(queue_)
            delete[] queue_;
        queue_ = newQueue;
        capacity_ *= 2;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            resize();
        }

        queue_[++rear_ %= capacity_] = item;
    }

    void dequeue(){
        assert(!isEmpty());

        ++front_ %= capacity_;
    }

    void print(){
        using namespace std;

        for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_) {
            cout << queue_[i] << " ";
        }
        cout << '\n';

        if (print_debug_) {
            printDebug();
        }
    }

    void printDebug(){
        using namespace std;

        cout << "Cap = " << capacity_ << ", Size = " << size() << '\n';

        for (int i = 0; i < capacity_; i++) {
            if (i == front_) cout << " F ";
            else if (i == rear_) cout << " R ";
            else cout << "   ";
        }
        cout << endl;

        for (int i = 0; i < capacity_; i++)
            cout << setw(2) << i << " ";
        cout << endl;

        if (front_ < rear_)
        {
            // front 앞 사용하지 않은 공간
            for (int i = 0; i < front_ + 1; i++)
                cout << " - ";

            // 저장된 내용물
            for (int i = front_ + 1; i <= rear_; i++)
                cout << setw(2) << queue_[i] << " ";

            // rear 뒤 사용하지 않은 공간
            for (int i = rear_ + 1; i < capacity_; i++)
                cout << " * ";

            cout << endl << endl;
        }
        else if (front_ > rear_)
        {
            // rear 이전에 저장된 내용물
            for (int i = 0; i <= rear_; i++)
                cout << setw(2) << queue_[i] << " ";

            // rear와 front 사이 사용하지 않은 공간
            for (int i = rear_ + 1; i <= front_; i++)
                cout << " * ";

            // front 뒤 내용물
            for (int i = front_ + 1; i < capacity_; i++)
                cout << setw(2) << queue_[i] << " ";

            cout << endl << endl;
        }
        else // 비었을 경우
        {
            for (int i = 0; i < capacity_; i++)
                cout << " - ";
            cout << endl << endl;
        }
    }

    void setDebugFlag(bool flag){
        print_debug_ = flag;
    }

protected:
    T* queue_;
    int front_ = 0;
    int rear_ = 0;
    int capacity_;
    bool print_debug_ = false;
};