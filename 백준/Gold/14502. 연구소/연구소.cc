#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, M;
vector<vector<int>> arr;
int dirr[] = { 0,0,1,-1 };
int dirc[] = { 1,-1,0,0 };
int ans;

int infec(vector<vector<int>> kim) {
	queue<Node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (kim[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nrow = now.row + dirr[dir];
			int ncol = now.col + dirc[dir];
			if (nrow < 0 || nrow >= N || ncol < 0 || ncol >= M) continue;
			if (kim[nrow][ncol]) continue;
			kim[nrow][ncol] = 2;
			q.push({ nrow, ncol });
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (kim[i][j] == 0) temp++;
		}
	}
	return temp;
}

void dfs(int now) {
	if (now == 3) {
		int temp = infec(arr);
		if (ans < temp) ans = temp;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 || arr[i][j] == 2) continue;
			arr[i][j] = 1;
			dfs(now + 1);
			arr[i][j] = 0;
		}
	}
}

int main() {	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		arr.push_back(v);
	}
	ans = 0;
	dfs(0);
	cout << ans;

	return 0;
}