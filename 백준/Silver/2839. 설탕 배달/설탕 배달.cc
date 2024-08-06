#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt5;
	int cnt3;
	int sum = -1;
	int minCnt = n / 3;
	int max5 = n / 5;
	for (int i = max5; i >=0; i--) {
		cnt5 = i;
		
		
		int rest = n - 5*i;
		if (rest % 3 == 0) {
			cnt3 = rest / 3;
			if (cnt3 + cnt5 <= minCnt) {
				minCnt = cnt3 + cnt5;
				sum = minCnt;
			}
		}
		
	}
	cout << sum;
}

