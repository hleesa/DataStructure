#include <iostream>

using namespace std;

int recurSum(int* arr, int n) {
    if (n ==  0) {
        return 0;
    }
    return arr[n - 1] + recurSum(arr, n - 1);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << recurSum(arr, n) << '\n';

    return 0;
}