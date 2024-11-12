#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[5][5];
bool visited[25];
vector<int> path;
int ans;

bool connec() {
	vector<pair<int, int>> v;
	bool arr2[5][5] = { false };
	for (int i = 0; i < path.size(); i++) {
		int row = path[i] / 5;
		int col = path[i] % 5;
		v.push_back({ row, col });		
	}
	queue<pair<int, int>> q;
	int dirr[] = { -1,1,0,0 };
	int dirc[] = { 0,0,-1,1 };
	q.push({ v[0].first, v[0].second });
	arr2[v[0].first][v[0].second] = true;
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nrow = row + dirr[dir];
			int ncol = col + dirc[dir];
			if (nrow < 0 || ncol < 0 || nrow >= 5 || ncol >= 5) continue;
			if (arr2[nrow][ncol]) continue;
			for (int i = 0; i < 7; i++) {
				if (nrow == v[i].first && ncol == v[i].second) {
					q.push({ nrow, ncol });
					arr2[nrow][ncol] = true;
					break;
				}
			}
		}
	}
	int seven = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr2[i][j]) seven++;
		}
	}
	if (seven == 7) return true;
	else return false;
}

void dfs(int now) {
	if (now == 7) {
		int danum = 0;
		for (int i = 0; i < 7; i++) {
			int row = path[i] / 5;
			int col = path[i] % 5;
			if (arr[row][col] == 'S') danum++;
		}
		if (4 <= danum) {
			if (connec()) ans++;
		}
		return;
	}
	for (int i = 0; i < 25; i++) {
		if (visited[i]) continue;
		if (now > 0 && i < path[now - 1]) continue;
		visited[i] = true;
		path.push_back(i);
		dfs(now + 1);
		path.pop_back();
		visited[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	ans = 0;
	dfs(0);
	cout << ans;
	return 0;
}