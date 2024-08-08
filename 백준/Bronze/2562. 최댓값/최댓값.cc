#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int maxnum = 0;
	int ind;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		if (num > maxnum) {
			maxnum = num;
			ind = i + 1;
		}
	}

	cout << maxnum << "\n" << ind;
}