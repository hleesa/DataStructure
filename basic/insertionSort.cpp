 #include <iostream>

using namespace std;

void print(int* arr, int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void insertionSort(int* arr, int n){
}

int main(){

    {
        int arr[] = {1, 2, 4, 5, 3, 6};
        int n = sizeof(arr) / sizeof(arr[0]);
        print(arr, n);

        int i = 4;

        int k = i - 1;
        while (k >= 0 && arr[k] > arr[i]) {
            --k;
        }
        ++k;

        for (int j = i; j > k; --j) {
            arr[j] = arr[j - 1];
            print(arr, n);
        }
        print(arr, n);

    }
}