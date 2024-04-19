#include <cassert>
#include <iostream>

using namespace std;

const int NUM_OF_LOWER_ALPHA = 26;

void printAlphaTable(char* arr, int n) {
    int alphaToNum[NUM_OF_LOWER_ALPHA] = {0,};

    for (int i = 0; i < n; ++i) {
        if ('a' <= arr[i] && arr[i] <= 'z') {
            ++alphaToNum[arr[i] - 'a'];
        }
    }
    for (int i = 0; i < NUM_OF_LOWER_ALPHA; ++i) {
        if(alphaToNum[i] == 0) continue;
        cout << static_cast<char>('a' + i) << alphaToNum[i];
    }
    cout << '\n';
    return;
}


void printAlpha(char* arr, int n) {
    for (int i = 0; i < NUM_OF_LOWER_ALPHA; ++i) {
        if (arr[i] < 'a' || 'z' < arr[i]) continue;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == static_cast<char>('a' + i)) {
                ++cnt;
            }
        }
        if (cnt != 0) {
            cout << static_cast<char>('a' + i) << cnt;
        }
    }
    cout << '\n';
    return;
}


void insertionSort(char* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) // <- while 사용
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int sequentialSearch(char* arr, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int sortedCountHelper(char* arr, int n, int start) {
    int end = start;

    while(arr[end] == arr[start]) {
        ++end;
    }
    return end - start;
}

int sortedCount(char* arr, int n, int target){
    int i = sequentialSearch(arr, n, target);

    if (i >= 0) {
        return sortedCountHelper(arr, n, i);
    } else {
        return 0;
    }
}

void printAlphaSorted(char* arr, int n){
    insertionSort(arr, n);
    for (char c = 'a'; c <= 'z'; ++c) {
        int cnt = sortedCount(arr, n, c);
        if(cnt == 0) continue;
        cout << c << cnt;
    }
    cout << '\n';
    return;
}

int main(){
    // 문제
    // - 어떤 알파벳에 몇 번 나오는지로 출력
    // - 예시) aaabbccdddeeeff -> a3b2c2d3e3f2
    // - 알파벳은 총 26 글자

    char arr[] = "ababcdfdceeedag";
    int n = sizeof(arr) - 1;

    assert(n >= 0);
    cout << arr << '\n';
    printAlphaTable(arr, n);
    printAlpha(arr, n);
    printAlphaSorted(arr, n);
}


/*
 * 1. sizeof 사용 주의
 *  문자열의 길이와 배열의 크기가 같아서 사용 가능하다.
 *
 * 2. 정렬
 * 정렬도 생각하자.
 *
 */