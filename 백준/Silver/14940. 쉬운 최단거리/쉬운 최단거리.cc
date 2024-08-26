#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int arr[1001][1001] = { 0 };
int visited[1001][1001] = { 0 };
int n, m;
int targetY, targetX;
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,1,-1 };

struct Node {
	int y, x, dist;
};

void bfs(int y, int x) {
	queue<Node>q;
	q.push({ y,x,0 });
	visited[y][x] = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 0) continue;
			if (ny == y && nx == x)continue;
			if (visited[ny][nx] != 0 && visited[ny][nx] <= now.dist+1) continue;
			
			visited[ny][nx] = now.dist+1;
			q.push({ ny,nx,now.dist + 1 });

		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				targetY = i;
				targetX = j;
			}
		}
	}
	bfs(targetY, targetX);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0)visited[i][j] = -1;
			if (arr[i][j] == 0 || arr[i][j]==2) visited[i][j] = 0;
			cout << visited[i][j] << ' ';

		}
		cout << "\n";
	}
}

/*
5 5
2 1 1 1 1
0 0 0 0 1
0 1 1 1 1
0 1 0 0 0
0 1 1 1 1
*/