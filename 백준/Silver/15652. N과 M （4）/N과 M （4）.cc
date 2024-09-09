#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int>path;
void dfs(int start, int level) {
	if (level >= M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= N; i++) {
		path.push_back(i);
		dfs(i, level + 1);
		path.pop_back();
	}
}
int main() {
	cin >> N >> M;
	dfs(1, 0);
}