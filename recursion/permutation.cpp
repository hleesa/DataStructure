#include <iostream>

using namespace std;

void recurPermutation(char* arr, int left, int right) {

    if (left == right) {
        for (int i = 0; i <= right; ++i) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = left; i <= right; ++i) {
            swap(arr[i], arr[left]);
            recurPermutation(arr, left + 1, right);
            swap(arr[i], arr[left]);
        }
    }
}

void myPermutation(char* arr, int cur, int end, bool* vis, char* ans) {
    if (cur == end) {
        for (int i = 0; i < end; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < end; ++i) {
        if (vis[i]) continue;
        vis[i] = true;
        ans[cur] = arr[i];
        myPermutation(arr, cur + 1, end, vis, ans);
        vis[i] = false;
    }
}

int main() {

    char arr[] = "abcd";

//    const int n = sizeof(arr) / sizeof(arr[0]);
//    bool vis[n] = {false,};
//    char ans[n];
//    myPermutation(arr, 0, n - 1, vis, ans);

    recurPermutation(arr, 0, 2);

}