#pragma once

#include <cassert>
#include <stdint.h>
#include <iostream>

template<typename T>
class SinglyLinkedList {
public:
    struct Node {
        T item = T();
        Node* next = nullptr;
    };

    SinglyLinkedList() {

    }

    SinglyLinkedList(const SinglyLinkedList &other) {

    }

    ~SinglyLinkedList() {
        clear();
    }

    void clear() {

    }

    bool isEmpty() {
        return first == nullptr;
    }

    int size() {
        int size = 0;

        return size;
    }

    T front() {
        assert(first);

        return T();
    }

    T back() {
        assert(first);

        return T();
    }

    Node* find(T item) {

        return nullptr;
    }

    void insertBack(Node* node, T item) {

    }

    void remove(Node* n) {
        assert(first);
    }

    void pushFront(T item) {

    }

    void pushBack(T item) {

    }

    void popFront() {

    }

    void popBack() {

    }

    void reverse() {

    }

    void setPrintDebug(bool flag) {
        printDebug = flag;
    }

    void print() {
        using namespace std;

        Node* current = first;

        if (isEmpty()) {
            cout << "empty\n";
        }
        else {
            cout << "size = " << size() << " ";

            while (current){
                if(printDebug) {
                    cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
                         << current->item << ", "
                         << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                }
                else{
                    cout << current->item;
                }

                if (current->next) {
                    cout << " -> ";
                }
                else {
                    cout << " -> NULL";
                }

                current = current->next;
            }
            cout << '\n';
        }
    }


protected:
    Node* first = nullptr;
    bool printDebug = false;
};