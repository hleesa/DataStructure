#include <iostream>

#include "../../shared/Stack.hpp"

using namespace std;

constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int dc[4] = {0, 0, -1, 1};
constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] =
        {
                {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
                {'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '1', '1', '1', '0', '1', '0', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '1', '1', '1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '1', '1', '1', '1', '0', '1', '1', '1'},
                {'1', '1', '1', '0', '0', '0', '1', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
                {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        };

void PrintMaze() {
    for (int j = 0; j < kNumRows; j++) {
        for (int i = 0; i < kNumCols; i++)
            cout << maze[j][i] << " ";
        cout << endl;
    }
}

struct Pos {
    int row;
    int col;

    // 디버깅을 위한 편의 기능
    friend ostream &operator<<(ostream &os, const Pos &pos) {
        cout << "(" << pos.row << ", " << pos.col << ")" << flush;
        return os;
    }
};

void RecurMaze(Pos p) {
    char &mark = maze[p.row][p.col];

    if (mark == 'G') {
        cout << "Found!" << endl;
        return;
    }
    else if (mark != '1' && mark != 'X') {
        mark = 'X';
        for (int d = 0; d < 4; ++d) {
            RecurMaze({p.row + dr[d], p.col + dc[d]});
        }
    }

}

//조기 종료가 가능한 버전
int RecurMazeFast(Pos p) {
    char &mark = maze[p.row][p.col];

    if (mark == 'G') {
        cout << "Found!" << endl;
        return 1;
    } else if (mark != '1' && mark != 'X') {
        mark = 'X';
        for (int d = 0; d < 4; ++d) {
            if (RecurMazeFast({p.row + dr[d], p.col + dc[d]})) {
                return 1;
            }
        }
    }
    return 0;
}

void StackMaze() {
    Stack<Pos> s;

    Pos start = {1, 1};
    s.push(start);


    while (!s.isEmpty()) {
        Pos p = s.top();
        s.pop();

        for (int d = 0; d < 4; ++d) {
            Pos next = {p.row + dr[d], p.col + dc[d]};
            const char mark = maze[next.row][next.col];
            if (mark == 'G') {
                cout << "Found!" << endl;
                break;
            } else if (mark == '0') {
                s.push(next);
                maze[next.row][next.col] = 'X';
            }
        }
    }
}

int main() {
    PrintMaze();

//    RecurMaze({1, 1});

    RecurMazeFast({1, 1});

//    StackMaze();

    PrintMaze();

    return 0;
}

