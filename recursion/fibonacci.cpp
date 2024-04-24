#include <iostream>
#include <iomanip>

using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        int fnbb = 0;
        int fnb = 1;
        int fn = 0;
        for (int i = 2; i <= n; ++i) {
            fn = fnb + fnbb;
            fnbb = fnb;
            fnb = fn;
        }
        return fn;
    }
}

int recurFibonacci(int n){
     if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return recurFibonacci(n - 1) + recurFibonacci(n - 2);
    }
}

int recurMemoFibonacci(int n, int* memo){
    if (n == 0) {
        return memo[n] = 0;
    }
    else if (n == 1) {
        return memo[n] = 1;
    }
    else {
        return memo[n] = memo[n - 1] + memo[n - 2];
    }
}

int main(){

    const int n = 15;
    cout << "input:         ";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << i << " ";
    }
    cout << '\n';

    cout << "fibonacci:     ";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << fibonacci(i) << " ";
    }
    cout << '\n';

    cout << "fibonacci:     ";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << recurFibonacci(i) << " ";
    }
    cout << '\n';

    int memo[n] = {0,};
    cout << "fibonacci:     ";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << recurMemoFibonacci(i, memo) << " ";
    }
    cout << '\n';
}