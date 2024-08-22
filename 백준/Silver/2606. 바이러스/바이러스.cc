#include <iostream>
#include <vector>
using namespace std;

int n;
int m;
vector<vector<int>>arr;
int dat[101] = { 0 };
int cnt = 0;

void dfs(int node) {
	for (int i = 0; i < n; i++) {
		if (arr[node][i] == 1 && dat[i]==0) {
			dat[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		arr.push_back(vector<int>(n));
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		arr[from - 1][to - 1] = 1;
		arr[to - 1][from - 1] = 1;

	}
	dat[0] = 1;
	dfs(0);

	cout << cnt;

	return 0;
}