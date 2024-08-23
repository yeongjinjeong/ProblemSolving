#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[500][500];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) arr[i][j] += arr[i - 1][j];
			else if (j == i) arr[i][j] += arr[i - 1][j - 1];
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
			}
		}
	}
	int maxNum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[N - 1][i] > maxNum) maxNum = arr[N - 1][i];
	}

	cout << maxNum;
	
}