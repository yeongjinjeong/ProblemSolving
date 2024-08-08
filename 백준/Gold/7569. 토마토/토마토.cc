#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H;
int tomato[100][100][100] = { 0 };
int visited[100][100][100] = { 0 };
int zero=0;
int day = 0;
struct Riped {
	int z;
	int y;
	int x;
	int time;
};
int zdir[6] = { 1,-1,0,0,0,0 };
int ydir[6] = { 0,0,1,-1,0,0 };
int xdir[6] = { 0,0,0,0,1,-1 };
queue<Riped>q;
void bfs() {
	
	while (!q.empty()) {
		Riped now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int h = now.z + zdir[i];
			int n = now.y + ydir[i];
			int m = now.x + xdir[i];
			if (h < 0 || n < 0 || m < 0 || h >= H || n >= N || m >= M) continue;
			if (tomato[h][n][m] == -1) continue;
			if (visited[h][n][m] == 1)continue;
			visited[h][n][m] = 1;
			tomato[h][n][m] = 1;
			zero--;
			q.push({ h,n,m,now.time + 1 });
			
			day = now.time + 1;
		}
	}
}
int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) zero++;
				if (tomato[i][j][k] == 1) {
					q.push({ i,j,k,0 });
					visited[i][j][k] = 1;
				}
			}
		}
	}

	if (zero == 0) {
		cout << 0;
		return 0;
	}
	else {
		bfs();
		if (zero != 0) cout << -1;
		else cout << day;
	}
	
}