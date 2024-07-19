#pragma once

#include <cassert>
#include <stdint.h>
#include <iostream>
#include "../shared/Stack.hpp"

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
        Node* thisCur = new Node();
        Node* otherCur = other.first;
        while (otherCur) {
            thisCur->item = otherCur->item;
            otherCur = otherCur->next;
            if (otherCur) {
                thisCur->next = new Node();
            }
        }
    }

    ~SinglyLinkedList() {
        clear();
    }

    void clear() {
        while (first) {
            Node* nodeToDelete = first;
            first = first->next;
            delete nodeToDelete;
        }
    }

    bool isEmpty() {
        return first == nullptr;
    }

    int size() {
        int size = 0;
        Node* nodeToCount = first;
        while (nodeToCount) {
            ++size;
            nodeToCount = nodeToCount->next;
        }
        return size;
    }

    T front() {
        assert(first);
        return first->item;
    }

    T back() {
        assert(first);
        Node* nodeToBack = first;
        while (nodeToBack->next) {
            nodeToBack = nodeToBack->next;
        }
        return nodeToBack->item;
    }

    Node* find(T item) {
        Node* nodeToFind = first;
        while (nodeToFind) {
            if (nodeToFind->item == item) {
                return nodeToFind;
            }
        }
        return nullptr;
    }

    void insertBack(Node* node, T item) {
        Node* nodeToInsert = new Node();
        nodeToInsert->item = item;
        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
    }

    void remove(Node* node) {
        assert(first);
        Node* nodeBeforeToRemove = first;
        while (nodeBeforeToRemove->next) {
            if (nodeBeforeToRemove->next == node) {
                Node* nodeToRemove = nodeBeforeToRemove->next;
                nodeBeforeToRemove->next = nodeBeforeToRemove->next->next;
                delete nodeToRemove;
                return;
            }
            nodeBeforeToRemove = nodeBeforeToRemove->next;
        }
        return;
    }

    void pushFront(T item) {
        Node* nodeToFront = new Node();
        nodeToFront->item = item;
        nodeToFront->next = first;
        first = nodeToFront;
    }

    void pushBack(T item) {
        if (first == nullptr) {
            first = new Node();
            first->item = item;
            return;
        }
        Node* cur = first;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new Node();
        cur->next->item = item;
    }

    void popFront() {
        assert(first);
        Node* toDelete = first;
        first = first->next;
        delete toDelete;
    }

    void popBack() {
        assert(first);
        int size = this->size();
        Node* newBack = first;
        for (int i = 0; i + 2 < size; ++i) {
            newBack = newBack->next;
        }
        Node* toDeleteNode = size == 1 ? newBack : newBack->next;
        delete toDeleteNode;
        newBack = nullptr;
    }

    void reverse() {
        Stack<Node*> stk;
        Node* cur = first;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        cur = first;
        while (!stk.isEmpty()) {
            cur->item = stk.top()->item;
            stk.pop();
        }
        return;
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
            cout << "size = " << size() << ", ";

            while (current) {
                if (printDebug) {
                    cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
                         << current->item << ", "
                         << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                }
                else {
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