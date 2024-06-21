#include <iostream>
#include "../shared/Queue.hpp"
#include "../shared/Stack.hpp"

using namespace std;

int prec(char c);
void infixToPostfix(Queue<char> &q, Queue<char> &output);
int evalPostfix(Queue<char> &queue);

int main()
{
    // 예제에서는 빈칸 없이 한 자리 숫자만 가능

//    const char infix[] = "8/2+(3+4)*5-1*2";
//    const char infix[] = "1+(1*2+3)*4";
//    const char infix[] = "1+2*3+3";
    const char infix[] = "1+2*(3+1)";
    const int size = sizeof(infix) / sizeof(char) - 1;

    // 큐에 모두 넣기
    Queue<char> q;
    for (int i = 0; i < size; i++)
        q.enqueue(infix[i]);

    Queue<char> postfix;

    cout << "Infix: ";
    q.print();
    cout << endl;

    infixToPostfix(q, postfix);

    cout << "Postfix: ";
    postfix.print();

    cout << "Evaluated = " << evalPostfix(postfix) << endl;

    return 0;
}


// Function to return precedence of operators
int prec(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // '('는 우선순위가 아주 낮은 것으로 처리, ')' 닫는 괄호를 만날때까지 남겨두기 위함
}

void infixToPostfix(Queue<char>& q, Queue<char>& output)
{
    Stack<char> s; // 우선순위가 낮은 연산을 보류하기 위한 스택

    output.setDebugFlag(false);

    while (!q.isEmpty())
    {
        char c = q.front();
        q.dequeue();

        cout << c << endl;

        if ('0' <= c && c <= '9')
        {
            output.enqueue(c);
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while(!s.isEmpty() && s.top() != '('){
                output.enqueue(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.isEmpty() && prec(s.top()) >= prec(c)){
                output.enqueue(s.top());
                s.pop();
            }
            s.push(c);
        }

        cout << "Stack: ";
        s.print();
        cout << "Output:";
        output.print();
        cout << endl;
    }

    while (!s.isEmpty())
    {
        output.enqueue(s.top());
        s.pop();
    }
}

int evalPostfix(Queue<char>& q)
{
    Stack<int> s;

    while (!q.isEmpty())
    {
        char c = q.front();
        q.dequeue();

        cout << c << endl;

        if (c != '+' && c != '-' && c != '*' && c != '/')
        {
            s.push(c - '0');
        }
        else
        {
            cout << "Operator: " << c << endl;

            if(s.size() < 2) {
                cout << "Wrong formula" << endl;
                exit(-1); // 강제 종료
            }

            int rhs = s.top();
            s.pop();
            int lhs = s.top();
            s.pop();

            int result = 0;
            if (c == '+') {
                result = lhs + rhs;
            }
            else if (c == '-') {
                result = lhs - rhs;
            }
            else if (c == '*') {
                result = lhs * rhs;
            }
            else if (c == '/')
            {
                result = lhs / rhs;
            }
            else
            {
                cout << "Wrong operator" << endl;
                exit(-1); // 강제 종료
            }
            s.push(result);
        }

        cout << "Stack: ";
        s.print();
    }

    return s.top();
}

