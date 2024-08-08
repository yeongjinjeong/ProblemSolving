#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int minValue = 1000000;
	int maxValue = -1000000;

	int N;
	cin >> N;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < minValue) minValue = arr[i];
		if (arr[i] > maxValue) maxValue = arr[i];
	}
	cout << minValue << ' ' << maxValue;
}