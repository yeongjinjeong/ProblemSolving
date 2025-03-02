#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

struct City {
	int dest;
	int cost;
	bool operator<(City right)const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

vector<City>* arr;
vector<int> dist;
int N, M;

void dijkstra(int A) {
	priority_queue<City>pq;
	dist.resize(N+1, 21e8);
	
	pq.push({A,0});

	while (!pq.empty()) {
		City now = pq.top(); pq.pop();
		
		if (dist[now.dest] <= now.cost) continue;
		dist[now.dest] = now.cost;
		for (int i = 0; i < arr[now.dest].size(); i++) {
			
			City next = arr[now.dest][i];

			if (dist[next.dest] <= now.cost + next.cost) continue;
			next.cost += now.cost;
			pq.push(next);
			
		}
	}
}

int main() {
	cin >> N >> M;

	arr = new vector<City>[N + 1];
	


	for (int i = 0; i < M; i++) {
		int st, en, co;
		cin >> st >> en >> co;
		arr[st].push_back({ en,co });
		
	}

	int A, B;
	cin >> A >> B;
	dijkstra(A);

	cout << dist[B];
}
