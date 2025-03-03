#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge {
	int dest;
	int cost;
	bool operator<(Edge right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

int start;
vector<Edge>* arr;
vector<int>dist;
int V, E;

void dijkstra(int start) {
	dist.resize(V+1, 21e8);
	priority_queue<Edge>pq;
	
	pq.push({ start,0 });
	
	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (dist[now.dest] <= now.cost) continue;
		dist[now.dest] = now.cost;

		for (int i = 0; i < arr[now.dest].size(); i++) {
			Edge next = arr[now.dest][i];
			int nextcost = now.cost + next.cost;
			if (dist[next.dest] <= nextcost) continue;
			pq.push({ next.dest,nextcost });

		}
	}
}

int main() {
	cin >> V >> E;
	cin >> start;

	arr = new vector<Edge>[V + 1];

	for (int i = 0; i < E; i++) {
		int st, en, co;
		cin >> st >> en >> co;
		arr[st].push_back({ en,co });

	}

	dijkstra(start);
	for (int i = 1; i < V + 1; i++) {
		if (dist[i] >= 21e8) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

}