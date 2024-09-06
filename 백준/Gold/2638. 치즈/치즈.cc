#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>>arr;
int totalCnt=0, time=0;
queue<pair<int, int>>one;
int ydir[4] = { 1,-1,0,0 };
int xdir[4] = { 0,0,-1,1 };
vector<vector<int>>air;
void airCheck() {
	
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	air[0][0] = 2;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.first + ydir[i];
			int nx = now.second + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 1)continue;
			if (air[ny][nx] == 2)continue;
			air[ny][nx] = 2;
			q.push({ ny,nx });
			
		}
	}

}
void bfs() {
	vector<pair<int,int>>tmp;
	int oneSize = one.size();
	int oneCnt = 0;
	while (!one.empty()) {
		pair<int, int> now = one.front();one.pop();
		oneCnt++;
		int check = 0;
		for (int i = 0; i < 4; i++) {
			int ny = now.first + ydir[i];
			int nx = now.second + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 1)continue;
			if (air[ny][nx]==-1)continue;
			check++;
		}
		if (check > 1) {
			tmp.push_back({ now.first, now.second });
		}
		else {
			one.push(now);
		}
		//한 바퀴 돌았을때 -> 0으로 만들고,  타임 증가, 다음 바퀴  one 개수 초기화
		if (oneCnt == oneSize) {
			for (int i = 0; i < tmp.size(); i++) {
				arr[tmp[i].first][tmp[i].second] = 0;
				totalCnt--;
			}
			tmp.clear();
			time++;
			oneCnt = 0;
			oneSize = one.size();
			air.clear();
			for (int i = 0; i < N; i++) {
				air.push_back(vector<int>(M,-1));
			}
			airCheck();
		}


	}
}
int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		arr.push_back(vector<int>(M));
		air.push_back(vector<int>(M,-1));
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				totalCnt += 1;
				one.push({ i,j });
			}
		}
	}
	airCheck();
	bfs();

	cout << time;
}
