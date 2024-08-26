#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

queue<int>q;
void Push() {
    int n;
    cin >> n;
    q.push(n);
}
void Front() {
    int front;
    if (q.size() == 0) {
        front = -1;
    }
    else {
        front = q.front();
    }
    cout << front << "\n";
}
void Back() {
    int back;
    if (q.size() == 0) {
        back = -1;
    }
    else {
        back = q.back();
    }
    cout << back << "\n";
}
void Empty() {
    if (q.size() == 0) {
        cout << 1 << "\n";
    }
    else {
        cout << 0<<"\n";
    }
}
void Size() {
    cout << q.size()<<"\n";
}
void Pop() {
    int front;
    if (q.size() == 0) {
        front = -1;
    }
    else {
        front = q.front();
        q.pop();
    }
    cout << front << "\n";
    
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
        if (command == "push") Push();
        else if (command == "pop") Pop();
        else if (command == "front")Front();
        else if (command == "back")Back();
        else if (command == "size")Size();
        else if (command == "empty")Empty();
    }
    
}
