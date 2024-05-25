#include "../shared/Deque.hpp"

#include <iostream>

int main()
{
    // Double Ended Queue (덱)
    Deque<char> d(8);

    d.setDebugFlag(true);

    d.print();

    d.pushFront('A');
    d.print();

    d.pushFront('B');
    d.print();

    d.pushBack('C');
    d.print();

    d.pushBack('D');
    d.print();

    d.popFront();
    d.print();

    d.popBack();
    d.print();

    return 0;
}

