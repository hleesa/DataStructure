#include <iostream>

#include "../shared/Stack.hpp" // 경로 "shared" 주의

int main()
{
    using namespace std;

    // 일종의 가방(bag), 컨테이너(container)
    // LIFO(Last-In-First-Out)

    Stack<char> s;

    s.push('A');
    s.print();

    s.push('B');
    s.print();

    s.push('C');
    s.print();

    cout << "top = " << s.top() << endl;

    s.pop();
    s.print();

    cout << "top = " << s.top() << endl;

    s.pop();
    s.print();

    s.push('E');
    s.print();

    s.pop();
    s.print();

    cout << "top = " << s.top() << endl;

    s.pop();

//     cout << "top = " << s.top() << endl; // 비었을 때 top() 불가

    // 다른 자료형의 stack도 쉽게 만들 수 있어요.
    {
        Stack<int> int_stack;
        int_stack.push(123);
        cout << int_stack.top() << endl;
        int_stack.top();
    }

    // 문자열 순서 뒤집어서 출력하기 (스택 사용하기 연습)
    {
        const char str[] = "Hello, World!";
        const int size = sizeof(str) - 1; // 마지막 '\0' 제외

        cout << "Input: " << str << endl;

        Stack<char> stack;

        for(int i=0; i<size; ++i){
            stack.push(str[i]);
        }

        cout << "Output: ";
        while (!stack.isEmpty()) {
            cout << stack.top();
            stack.pop();
        }
        cout << '\n';
    }

    return 0;
}
