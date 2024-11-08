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
vector<Node> zero;
vector<int> visited;
vector<int> path;
int dirr[] = { 0,0,1,-1 };
int dirc[] = { 1,-1,0,0 };
int ans;

int infec() {
	queue<Node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	vector<vector<int>> kim = arr;
	for (int i = 0; i < 3; i++) {
		int row = zero[path[i]].row;
		int col = zero[path[i]].col;
		kim[row][col] = 1;
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
		int temp = infec();
		if (ans < temp) ans = temp;
		return;
	}
	for (int i = 0; i < zero.size(); i++) {
		if (visited[i]) continue;
		if (now > 0 && i < path[now - 1]) continue;
		path.push_back(i);
		visited[i] = 1;
		dfs(now + 1);
		visited[i] = 0;
		path.pop_back();				
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) zero.push_back({ i,j });
			v.push_back(temp);
		}
		arr.push_back(v);
	}
	ans = 0;
	for (int i = 0; i < zero.size(); i++) {
		visited.push_back(0);
	}
	dfs(0);
	cout << ans;

	return 0;
}