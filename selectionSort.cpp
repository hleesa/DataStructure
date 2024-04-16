#include <cassert>
#include <iostream>

using namespace std;

void selectionSort(int* arr, int size) {
    for (int i = 0; i + 1 < size; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

bool checkSortedAsc(int* arr, int size) {
    for (int i = 0; i + 1 < size; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
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
 */