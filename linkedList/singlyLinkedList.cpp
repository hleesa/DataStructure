#include <iostream>

#include "../shared/singlyLinkedList.hpp"

using namespace std;

int main()
{
    SinglyLinkedList<int> list;

    list.setPrintDebug(false);

    list.pushFront(3);
    list.pushBack(4);
    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(5);

    list.print();

    // copy constructor
    {
        SinglyLinkedList<int> list2 = list; // copy constructor
        list2.setPrintDebug(false);
        list2.print();
    }

    list.reverse();
    list.print();

    SinglyLinkedList<int>::Node* temp = list.find(3);
    list.insertBack(temp, 1000);
    list.print();

    list.insertBack(temp, 50);
    list.print();
    list.remove(temp);
    list.print();

    // PopFront()/Back() 테스트
    for (int i = 0; i < 5; i++)
    {
        //list.PopFront();
        //list.print();

        list.popBack();
        list.print();

        if (!list.isEmpty())
            cout << list.front() << " " << list.back() << endl;
    }

    // Edge case 테스트 주의

    return 0;
}
