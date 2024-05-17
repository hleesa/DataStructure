#include <iostream>
#include "../../shared/Stack.hpp"

using namespace std;

Stack<char> tower[3];

void PrintTowers() {
    cout << "Towers" << endl;
    cout << "0: ";
    tower[0].print();
    cout << "1: ";
    tower[1].print();
    cout << "2: ";
    tower[2].print();
}

void MoveDisk(int from, int to) {
    if (tower[from].isEmpty()) {
        cout << "Tower " << from << " is empty." << endl;
        exit(0);
    }

    auto disk = tower[from].top();

    if (!tower[to].isEmpty() && tower[to].top() > disk) {
        cout << "Cannot place " << disk << " on " << tower[to].top() << endl;
        exit(0);
    }

    tower[from].pop();
    tower[to].push(disk);

    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    PrintTowers();
}

void recurMoveDisks(int n, int from, int temp, int to) {
    if (n == 0)
        return;

    recurMoveDisks(n - 1, from, to, temp);
    MoveDisk(from, to);  // 1개를 from -> to (가장 큰 것)
    recurMoveDisks(n - 1, temp, from, to);
}

int main() {
    int num_disks = 5;

    for (int i = 0; i < num_disks; i++)
        tower[0].push('A' + i);

    PrintTowers();

//     MoveDisk(0, 2); // <- 디스크 하나만 움직이는 함수 tower 0 -> tower 2

    recurMoveDisks(num_disks, 0, 1, 2);


    return 0;
}

