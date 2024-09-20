#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int N = 12, M = 6; //가로세로
string arr[12];
vector<vector<int>>visited;
int ydir[] = { 1,-1,0,0 };
int xdir[] = { 0,0,1,-1 };

//한 턴에 터트리는 코드
//bfs,같은거 벡터에 저장 개수 4개 이상이면 . 으로 바꿈
bool bfs(int y, int x) {
	queue<pair<int, int>>q;
	vector<pair<int, int>>path;
	char target = arr[y][x];
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		pair<int, int>now = q.front();
		path.push_back(now);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.first + ydir[i];
			int nx = now.second + xdir[i];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] == 1)continue;
			if (arr[ny][nx] != target)continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });

		}

	}
	if (path.size() >= 4) {
		for (int i = 0; i < path.size(); i++) {
			arr[path[i].first][path[i].second] = '.';
			
		}
		return true;
	}
	return false;
}
bool bomb() {
	bool check = false;
	visited.clear();
	visited.resize(12, vector<int>(6,0));
	for (int i = 11; i > 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == '.')continue;
			if (visited[i][j] == 1)continue;
			if (bfs(i, j)) check = true;
		}
	}
	return check;
}

void arrange() {
	for (int i = 0; i < 6; i++) {
		vector<char>puyo;
		for (int j = 0; j < 12; j++) {
			if (arr[j][i] != '.') puyo.push_back(arr[j][i]);
		}
		int vecSize = puyo.size();
		int j=11;
		for (int cnt = 0; cnt < vecSize; cnt++) {
			arr[j--][i] = puyo[vecSize - 1 - cnt];
		}
		for (j=j; j!=11 && j >= 0; j--) {
			arr[j][i] = '.';
		}
	}
}
int main() {
	for (int i = 0; i < 12; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	while (bomb()) {
		cnt++;
		arrange();
	}

	cout << cnt;

}
