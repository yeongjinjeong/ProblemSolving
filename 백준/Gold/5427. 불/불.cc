#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int T,w,h;
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,1,-1 };

vector<string>arr;
vector<vector<int>>visited;
queue<pair<int,int>>fire;
queue<pair<int, int>>sang;
int minCnt;

void bfs() {
	int fireCnt = fire.size();
	int popCnt=0;
	int sangValue = 0;
	while(!fire.empty()) {
		pair<int, int>now = fire.front();
		if (sang.empty())return;
		pair<int, int> sangNow = sang.front();
		fire.pop();
		popCnt++;
		for (int i = 0; i < 4; i++) {
			int ny = now.first + ydir[i];
			int nx = now.second + xdir[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (arr[ny][nx] == '#' || arr[ny][nx] == '*')continue;
			fire.push({ ny,nx });
			arr[ny][nx] = '*';
			visited[ny][nx] = -1;
		}
		if (popCnt == fireCnt) {
			fireCnt = fire.size();
			popCnt = 0;
			int sangCnt = sang.size();
			for (int i = 0; i < sangCnt; i++) {
				pair<int, int> sangNow = sang.front();
				sang.pop();
				for (int j = 0; j < 4; j++) {
					int ny = sangNow.first + ydir[j];
					int nx = sangNow.second + xdir[j];
					if (visited[ny][nx] != 0) continue;
					if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
					if (ny == 0 || nx == 0 || ny == h-1 || nx == w-1) {
						minCnt = sangValue + 1+1;
						return;
					}
					visited[ny][nx] = sangValue + 1;
					sang.push({ ny,nx });
				}
			}
			sangValue++;
		}
	}
}

void bfs_sang() {
	int sangValue = 0;
	while (!sang.empty()) {
		int sangCnt = sang.size();
		for (int i = 0; i < sangCnt; i++) {
			pair<int, int> sangNow = sang.front();
			sang.pop();
			for (int j = 0; j < 4; j++) {
				int ny = sangNow.first + ydir[j];
				int nx = sangNow.second + xdir[j];
				if (visited[ny][nx] != 0) continue;
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (ny == 0 || nx == 0 || ny == h - 1 || nx == w - 1) {
					minCnt = sangValue + 1 + 1;
					return;
				}
				visited[ny][nx] = sangValue + 1;
				sang.push({ ny,nx });
			}
		}
		sangValue++;
	}
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> w >> h;
		arr.clear();
		minCnt = 2147483647;
		visited.clear();
		fire= queue<pair<int,int>>();
		sang = queue<pair<int, int>>();
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			arr.push_back(str);
			visited.push_back(vector<int>(w));
			for (int j = 0; j < w; j++) {
				
				if (arr[i][j] == '.')visited[i][j] = 0;
				else visited[i][j] = -1;

				if (arr[i][j] == '@') {
					sang.push({ i,j });
					visited[i][j] = 0;
				}
				if (arr[i][j] == '*') {
					fire.push({ i,j });
				}

			}
		}
		pair<int, int> check = sang.front();
		int y = check.first;
		int x = check.second;
		if (y == 0 || x == 0 || y == h - 1 || x == w - 1) {
			minCnt = 1;
		}
		else if (!fire.empty()) {
			bfs();
		}
		else
			bfs_sang();
		if (minCnt == 2147483647) {
			cout << "IMPOSSIBLE"<<"\n";
		}
		else cout << minCnt << "\n";
	}

}
