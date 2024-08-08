#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<int>dat(42);
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		int res = num % 42;
		dat[res] += 1;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (dat[i] != 0) cnt++;
	}
	cout << cnt;
}