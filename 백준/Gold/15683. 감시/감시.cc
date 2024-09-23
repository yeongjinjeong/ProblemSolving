#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>>arr;
vector<vector<int>>visited;
int zeroCnt = 0;
int minCnt;
struct Cctv {
	int y, x, num;
};
int ydir[] = { 1,0,-1,0,1 };
int xdir[] = { 0,1,0,-1,0 };
vector<Cctv>cctv;

void func(int level);

void type1(int level) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max(N, M); j++) {
			int ny = cctv[level].y + ydir[i]*j;
			int nx = cctv[level].x + xdir[i]*j;
			if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
			if (arr[ny][nx] == 6)break;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = -1; //-1은 감사하고 있는 지역
				visited[ny][nx] = level;
				zeroCnt--;
			}
		}
		func(level + 1);
		for (int j = 0; j < max(N, M); j++) {
			int ny = cctv[level].y + ydir[i] * j;
			int nx = cctv[level].x + xdir[i] * j;
			if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
			if (arr[ny][nx] == 6)break;
			if (arr[ny][nx] == -1 && visited[ny][nx]== level) {
				arr[ny][nx] = 0;
				zeroCnt++;
			}
		}
	}
}
void type2(int level) {
	for (int i = 0; i < 2; i++) {
		for (int j = i; j < 4; j += 2) {
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = -1; //-1은 감사하고 있는 지역
					visited[ny][nx] = level;
					zeroCnt--;
				}
			}
		}
		func(level + 1);
		for (int j = i; j < 4; j += 2) {
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == -1 && visited[ny][nx] == level) {
					arr[ny][nx] = 0;
					zeroCnt++;
				}
			}
		}
	}
}
void type3(int level) {
	for (int i = 0; i < 4; i++) {
		for (int j = i; j <=i+1; j ++) {
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = -1; //-1은 감사하고 있는 지역
					visited[ny][nx] = level;
					zeroCnt--;
				}
			}
		}
		func(level + 1);
		for (int j = i; j <= i + 1; j++) {
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == -1 && visited[ny][nx] == level) {
					arr[ny][nx] = 0;
					zeroCnt++;
				}
			}
		}
	}
}
void type4(int level) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == i) continue;
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = -1; //-1은 감사하고 있는 지역
					visited[ny][nx] = level;
					zeroCnt--;
				}
			}
		}
		func(level + 1);
		for (int j = 0; j < 4; j++) {
			if (j == i) continue;
			for (int k = 0; k < max(N, M); k++) {
				int ny = cctv[level].y + ydir[j] * k;
				int nx = cctv[level].x + xdir[j] * k;
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
				if (arr[ny][nx] == 6)break;
				if (arr[ny][nx] == -1 && visited[ny][nx] == level) {
					arr[ny][nx] = 0;
					zeroCnt++;
				}
			}
		}
	}
}
void type5(int level) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max(N, M); j++) {
			int ny = cctv[level].y + ydir[i] * j;
			int nx = cctv[level].x + xdir[i] * j;
			if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
			if (arr[ny][nx] == 6)break;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = -1; //-1은 감사하고 있는 지역
				visited[ny][nx] = level;
				zeroCnt--;
			}
		}
	}
	func(level + 1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max(N, M); j++) {
			int ny = cctv[level].y + ydir[i] * j;
			int nx = cctv[level].x + xdir[i] * j;
			if (ny < 0 || nx < 0 || nx >= M || ny >= N)break;
			if (arr[ny][nx] == 6)break;
			if (arr[ny][nx] == -1 && visited[ny][nx] == level) {
				arr[ny][nx] = 0;
				zeroCnt++;
			}
		}
	}
}

void func(int level) {
	if (level >= cctv.size()) {
		if (zeroCnt < minCnt) minCnt = zeroCnt;
		return;
	}
	if (cctv[level].num == 1) type1(level);
	else if (cctv[level].num == 2) type2(level);
	else if (cctv[level].num == 3) type3(level);
	else if (cctv[level].num == 4) type4(level);
	else if (cctv[level].num == 5) type5(level);

}

int main() {
	cin >> N >> M;
	
	arr.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] < 6 && arr[i][j]>0) {
				cctv.push_back({ i,j,arr[i][j] });
			}
			if (arr[i][j] == 0) zeroCnt++;
		}
	}

	minCnt = zeroCnt;

	func(0);
	cout << minCnt;





}


/*
4 5
0 0 2 0 3
0 6 0 0 0
0 0 6 6 0
0 0 0 0 0

*/