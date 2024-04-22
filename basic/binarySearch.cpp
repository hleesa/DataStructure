#include <cassert>
#include <iostream>

using namespace std;

int binarySearch(int* arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else if (target < arr[mid]) {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main() {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    assert(n > 0);

    cout << binarySearch(arr, n, 10) << '\n';

    return 0;
}

/*
 * 1. lowerbound, upperbound 구현 어떻게?
 */