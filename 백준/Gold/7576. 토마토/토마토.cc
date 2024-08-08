#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int zero = 0;
int N, M;
vector<vector<int>>tomato;
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,1,-1 };
struct Next {
	int m;
	int n;
	int level;
};
queue<Next>q;
int cnt=0;
void bfs() {
	
	while (!q.empty()) {
		Next now = q.front();
		q.pop();
		cnt = now.level;
		for (int i = 0; i < 4; i++) {
			int y = now.m + ydir[i];
			int x = now.n + xdir[i];
			if (y < 0 || x < 0 || x >= N || y >= M) continue;
			if (tomato[y][x] == -1 || tomato[y][x]==1) continue;
			q.push({ y,x, cnt+1 });
			zero--;
			tomato[y][x] = 1;
		}
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		tomato.push_back(vector<int>(N));
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 0) zero++;
			if (tomato[i][j] == 1) q.push({ i,j,0 });
		}
	}
	if (zero == 0) {
		cout << 0;
		return 0;
	}
	else {
		bfs();
		if (zero == 0) cout << cnt;
		else cout << -1;

		return 0;
	}
}