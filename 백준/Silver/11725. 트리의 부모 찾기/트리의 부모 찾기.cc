#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>ans(N+1);
	vector<int>visited(N + 1,0);
	vector<vector<int>>arr(N + 1);
	for (int i = 0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] == 1)continue;
			ans[next] = now;
			visited[next] = 1;
			q.push(next);
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}
