 #include <iostream>

using namespace std;

void print(int* arr, int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main(){

    {
//        int arr[] = {1, 2, 4, 5, 3, 6};
//        int arr[] = {1, 2, 3,4,5,6};
        int arr[] = {6, 5, 4, 3, 2, 1};
//        int arr[] = { 2, 1};
        int n = sizeof(arr) / sizeof(arr[0]);
        print(arr, n);

        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > key; --j) {
                arr[j] = arr[j - 1];
                print(arr, n);
            }
            arr[j] = key;
            print(arr, n);
        }
    }
}

/*
 * 1. insertion sort 구현 익숙하지 않아서 쉽지 않았다.
 *
 * 2. 이동하고 삽입할때 배열의 정확한 인덱스를 알아야함.
 *
 * 3. 복잡성을 줄이자.
 *  익숙하지 않든, 컨디션이 좋지 않든, 어려운 수준이든,
 *  어렵다면 복잡성을 줄이자.
 *  더 작은 문제로 나누자.
 */