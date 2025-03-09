#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Edge {
	int dest;
	int cost;
	bool operator<(Edge right)const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

int N, M, X;
vector<vector<Edge>>arr;
vector<int>ans;
vector<int>dist;

void dijkstra(int start) {
	dist.clear();
	dist.resize(N + 1, 21e8);
	priority_queue<Edge>pq;

	pq.push({ start,0 });

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		
		if (dist[now.dest] <= now.cost) continue;
		dist[now.dest] = now.cost;

		for (int i = 0; i < arr[now.dest].size(); i++) {
			Edge next = arr[now.dest][i];
			int nextCost = now.cost + next.cost;
			if (dist[next.dest] <= nextCost) continue;
			pq.push({ next.dest,nextCost });
		}
	}
}

int main() {
	cin >> N >> M >> X;

	arr.resize(N + 1);
	ans.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int st, en, co;
		cin >> st >> en >> co;
		arr[st].push_back({ en,co });
	}
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
		ans[i] = dist[X];
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		ans[i] += dist[i];
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < ans[i]) answer = ans[i];
	}
	cout << answer;
}