#include <cassert>
#include <iostream>

using namespace std;

struct Element{
    int key;
    char value;
};

void selectionSort(Element* arr, int size) {
    for (int i = 0; i + 1 < size; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j].key < arr[minIdx].key) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

bool checkSortedAsc(Element* arr, int size) {
    for (int i = 0; i + 1 < size; ++i) {
        if (arr[i].key > arr[i + 1].key) {
            return false;
        }
    }
    return true;
}

void print(Element* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "{ " << arr[i].key << ", " << arr[i].value << " } ";
    }
}

int main() {
    {
        Element arr[] = {{2, 'a'},
                         {2, 'b'},
                         {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);
        assert(size > 0);

        selectionSort(arr, size);
        cout << checkSortedAsc(arr, size) << '\n';
        print(arr, size);
    }

    return 0;
}

/*
 * 1. 검증 로직을 생각하지 않음
 *  실수할 수 있으니 테스트 해야함.
 *
 *  2. stable sort
 *   두 원소의 비교 결과가 같을 때, 입력된 원소 순서를 유지하면 stable sort.
 *   입력된 원소 순서를 유지하지 않으면 unstable sort.
 */