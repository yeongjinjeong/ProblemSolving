#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1000][3];
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 1; i < N; i++) {
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}
	int res = min(arr[N - 1][0], arr[N - 1][1]);
	res = min(res, arr[N - 1][2]);

	cout << res;
}