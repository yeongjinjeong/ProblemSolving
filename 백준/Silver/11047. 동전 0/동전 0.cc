#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;



int main() {
	int N, K;
	cin >> N >> K;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<>());
	int total = 0;
	for (int i = 0; i < N; i++) {
		int cnt = K / arr[i];
		total += cnt;
		K = K % arr[i];
		if (K == 0)break;
	}

	cout << total;
}
