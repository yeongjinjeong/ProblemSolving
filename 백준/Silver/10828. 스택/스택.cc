#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>st;
void Push() {
	int n;
	cin >> n;
	st.push_back(n);
}
void Top() {
	int top;
	if (st.size() == 0) {
		top = -1;
	}
	else {
		top = *st.rbegin();
	}
	cout << top << "\n";
}
void Empty() {
	if (st.size() == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0<<"\n";
	}
}
void Size() {
	cout << st.size()<<"\n";
}
void Pop() {
	int top;
	if (st.size() == 0) {
		top = -1;
	}
	else {
		top = *st.rbegin();
		st.pop_back();
	}
	cout << top << "\n";
	
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		if (command == "push") Push();
		else if (command == "pop") Pop();
		else if (command == "top")Top();
		else if (command == "size")Size();
		else if (command == "empty")Empty();
	}
	
}