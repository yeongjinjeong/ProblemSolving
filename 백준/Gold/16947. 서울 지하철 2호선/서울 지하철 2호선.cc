#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>>link;
vector<int>cycle;
vector<int>visited;

int bfs(int st) {
	queue<pair<int,int>> q;
	q.push({ st,0 });
	vector<int>visited2(N + 1,0);
	while (!q.empty()) {
		pair<int,int> now = q.front(); q.pop();
		visited2[now.first] = 1;
		for (int i = 0; i < link[now.first].size(); i++) {
			int next = link[now.first][i];
			int dist = now.second + 1;
			if (visited[next] == 1) continue;
			if (cycle[next] == 1) return dist;
			q.push({ next,dist });
			
		}
	}

}

void notcircle(int st,int pre) {
	for (int i = 0; i < link[st].size(); i++) {
		int next = link[st][i];
		if (next == pre)continue;
		if (cycle[next] == 0)continue;
		if (cycle[next] == 1) {
			cycle[next] = cycle[st] + 1;
			notcircle(next, st);
		}
	}
}

void dfs(int st,int now, int level) {
	
	for (int i = 0; i < link[now].size(); i++) {
		int next = link[now][i];
		if ( level> 1 && next == st) {
			//cout << st << endl;
			for (int i = 0; i < N + 1; i++) {
				if (visited[i] == 0) continue;

				cycle[i] = 0;
				//cout << i << " ";
			}
			//cout << endl;
			return;
		}
		if (visited[next] == 1)continue;
		visited[next] = 1;
		dfs(st, next, level + 1);
		visited[next] = 0;
		
	}
}

int main() {
	cin >> N;
	link.resize(N + 1);
	cycle.resize(N + 1, 1);
	visited.resize(N + 1, 0);

	for (int i = 0; i < N; i++) {
		int st, en;
		cin >> st >> en;
		link[st].push_back(en);
		link[en].push_back(st);
	}

	for (int i = 0; i < N + 1; i++) {
		if (cycle[i] == 0)continue;
		visited.clear();
		visited.resize(N + 1, 0);
		visited[i] = 1;
		dfs(i, i, 0);
	}
	//for (int i = 1; i < N + 1; i++) {
	//	cout << cycle[i] << ' ';
	//}

	//cout << endl;

	for (int i = 1; i < N + 1; i++) {
		int res;
		if (cycle[i] == 0) {
			notcircle(i,0);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		cout << cycle[i] << ' ';
	}


}

/*
사이클 확인
사이클에 포함이면 0, 아니면 사이클인 것까지 거리
사이클은 어차피 하나?
bfs??양쪽으로 퍼지는데 어떻게 돌아오는 걸 확인?
dfs??이걸로 사이클 확인
*/