#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<vector<int>>building;
vector<vector<int>>visited;
vector<int>num;

int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };

int bfs(int i, int j) {
	int cnt = 1;
	queue<pair<int, int>>q;
	visited[i][j] = 1;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int nowy = now.first;
		int nowx = now.second;
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + ydir[i];
			int nextx = nowx + xdir[i];
			if (nexty<0 || nexty>N - 1 || nextx<0 || nextx>N - 1) continue;
			if (visited[nexty][nextx] == 1)continue;
			if (building[nexty][nextx] == 0) {
				visited[nexty][nextx] = 1;
				continue;
			}
			
			q.push({ nexty,nextx });
			cnt++;
			visited[nexty][nextx] = 1;

		}
	}

	return cnt;

}

int main() {
	cin >> N;
	building.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		string data;
		cin >> data;
		for (int j = 0; j < N; j++) {
			building[i][j] = (int)(data[j]-'0');
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << building[i][j];
		}
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) continue;
			if (building[i][j] == 0) {
				visited[i][j] = 1;
				continue;
			}
			int cnt = bfs(i, j);
			num.push_back(cnt);
		}
	}

	sort(num.begin(), num.end());

	cout << num.size() << "\n";
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << "\n";
	}

}