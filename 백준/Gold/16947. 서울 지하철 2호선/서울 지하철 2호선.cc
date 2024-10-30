#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>>link;
vector<int>cycle;
vector<int>visited;

//최소거리 확인하는 코드
void notcircle(int st,int pre) {
	
	for (int i = 0; i < link[st].size(); i++) {
		int next = link[st][i];
		//이전 노드로 다시 가는 거 방지
		if (next == pre)continue;

		//사이클이면 거리를 최신화 필요 X
		if (cycle[next] == 0)continue;

		//사이클이 아닌 경우에 현재 최소거리에서 1추가해서 저장
		if (cycle[next] == 1) {
			cycle[next] = cycle[st] + 1;
			notcircle(next, st);
		}
	}
}

//사이클인지 아닌지 구분해주는 함수
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


	//연결관계 만들어주기
	for (int i = 0; i < N; i++) {
		int st, en;
		cin >> st >> en;
		link[st].push_back(en);
		link[en].push_back(st);
	}

	//사이클인지 아닌지 구분 => 사이클이면 0, 사이클이 아니면 1
	for (int i = 0; i < N + 1; i++) {
		if (cycle[i] == 0)continue;
		visited.clear();
		visited.resize(N + 1, 0);
		visited[i] = 1;
		dfs(i, i, 0);
	}

	//사이클인 경우에서 함수 호출
	
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
