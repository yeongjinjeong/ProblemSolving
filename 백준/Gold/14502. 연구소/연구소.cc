#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,1,-1 };
int arr[8][8] = { 0 };
int minVirus;

int cnt1 = 0;
int cnt2 = 0;

vector<pair<int, int>>virus;
void bfs() {
	queue<pair<int, int>>v;
	int visited[8][8] = { 0 };
	for (int i = 0; i < virus.size(); i++) {
		v.push(virus[i]);
	}
	int cnt = cnt2;
	while (!v.empty()) {
		pair<int, int>now = v.front(); v.pop();
		visited[now.first][now.second] = 1;
		for (int i = 0; i < 4; i++) {
			int nY = now.first + ydir[i];
			int nX = now.second + xdir[i];
			if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
			if (arr[nY][nX] == 1 || arr[nY][nX] == 2) continue;
			if (visited[nY][nX] == 1) continue;
			visited[nY][nX] = 1;
			cnt++;
			v.push({ nY,nX });
		}
		if (cnt > minVirus) break;
	}
	if (cnt < minVirus) minVirus = cnt;
}
void dfs(int level, int ind) {
	if (level >= 3) {
		bfs();
		return;
	}
	for (int i = 0; i < N*M; i++) {
		int y = i / M;
		int x = i % M;
		if (arr[y][x] == 2 || arr[y][x] == 1) continue;
		arr[y][x] = 1;
		dfs(level + 1, i);
		arr[y][x] = 0;

	}
}

int main() {
	cin >> N >> M;
	//minVirus = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				cnt1++;
			}
			if (arr[i][j] == 2) {
				cnt2++;
				virus.push_back({ i,j });
			}
		}
	}
	minVirus = N * M-cnt1;
	dfs(0, 0);
	//cout << minVirus;
	//cout << endl;
	int res = N * M - (cnt1 + 3) - minVirus;
	cout << res;
}