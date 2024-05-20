#include "../shared/Queue.hpp"

#include <iostream>

int main()
{
    // FIFO(First In First Out)

    Queue<char> q(2); // capacity_ = 2에서 시작 (메모리 증가 확인)

    q.setDebugFlag(true);

    q.print();

    q.enqueue('A');
    q.print();

    q.enqueue('B');
    q.print();

    q.enqueue('C');
    q.print();

    q.enqueue('D');
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    for (char c = 'E'; c <= 'K'; c++)
    {
        q.enqueue(c);
        q.print();
    }

    return 0;
}
