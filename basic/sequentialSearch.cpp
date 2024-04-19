#include <iostream>

using namespace std;

int count(int* arr, int n, int target) {
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            ++cnt;
        }
    }
    return cnt;
}

int sequentialSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int sortedCountHelper(int* arr, int n, int start) {
    int end = start;

    while(arr[end] == arr[start]) {
        ++end;
    }
    return end - start;
}


int sortedCount(int* arr, int n, int target){
    int i = sequentialSearch(arr, n, target);

    if (i >= 0) {
        return sortedCountHelper(arr, n, i);
    } else {
        return 0;
    }
}

int main() {

    int arr[] = {8, 1, 1, 3, 2, 5, 1, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 복잡한 알고리즘이나 자료구조를 개발할 때는
    // 실수할 가능성이 적은 단순한 방법을 기준으로 삼아요.

    cout << "Count 9 = " << count(arr, n, 9) << endl;
    cout << "Count 2 = " << count(arr, n, 2) << endl;
    cout << "Count 8 = " << count(arr, n, 8) << endl;
    cout << "Count 1 = " << count(arr, n, 1) << endl;
    cout << endl;

    cout << "Search 2 = " << sequentialSearch(arr, n, 2) << endl;
    cout << "Search 5 = " << sequentialSearch(arr, n, 5) << endl;
    cout << "Search 9 = " << sequentialSearch(arr, n, 9) << endl;
    cout << endl;

    insertionSort(arr, n);

    print(arr, n);

    cout << "Sorted Count 9 = " << sortedCount(arr, n, 9) << endl;
    cout << "Sorted Count 2 = " << sortedCount(arr, n, 2) << endl;
    cout << "Sorted Count 8 = " << sortedCount(arr, n, 8) << endl;
    cout << "Sorted Count 1 = " << sortedCount(arr, n, 1) << endl;
    cout << endl;

    return 0;
}

/*
 * 1. 정렬.
 *  정렬을 활용할 수 있다.
 */