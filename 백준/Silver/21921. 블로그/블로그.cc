#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;

	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = X - 1;
	int Sum = 0;
	for (int i = 0; i <= right; i++) {
		Sum += arr[i];
	}
	int maxSum = 0;
	int cnt = 0;
	while (right < N) {
		
		if (maxSum == Sum) {
			cnt++;
		}
		if (maxSum < Sum) {
			maxSum = Sum;
			cnt = 1;
		}

		Sum -= arr[left];
		left++;
		right++;
		if (right >= N) break;
		Sum += arr[right];
	}
	if (maxSum == 0) cout << "SAD";
	else {
		cout << maxSum << "\n";
		cout << cnt;
	}
}