#include <iostream>

using namespace std;

void print(int* arr, int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void bubbleSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        bool sorted = true;
        for (int j = 0; j + i < n; ++j) {
            if (arr[j + 1] < arr[j]) {
                sorted = false;
                swap(arr[j + 1], arr[j]);
            }
        }
        if (sorted) {
            return;
        }
    }
}

int main(){
    int arr[] = {8, 3, 2, 5, 1, 1, 2};
//    int arr[] = {5, 4, 3, 2, 1};
//    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    {
        print(arr, n);
        bubbleSort(arr, n);
    }
}

/*
 * 1. 생각보다 구현이 쉽지 않음.
 *
 * 2. early exit
 *
 * 3. stable sort
 *
 */

