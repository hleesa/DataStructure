#include <iostream>

using namespace std;

int recurBinarySearch(int* arr, int left, int right, int target) {

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            return recurBinarySearch(arr, mid + 1, right, target);
        }
        else if (arr[mid] > target) {
            return recurBinarySearch(arr, left, mid - 1, target);
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << recurBinarySearch(arr, 0, n - 1, 11) << '\n';

    return 0;
}