#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int Level;
vector<int>arr;
vector<int>visited;
vector<int>completed;
void dfs(int start) {
	visited[start] = 1;
	int next = arr[start];

	if (!visited[next]) {
		dfs(next);
	}
	else if (!completed[next]) {
		for (int i = next; i != start; i = arr[i]) Level--;
		//i==start인 경우 처리
		Level--;
	}

	completed[start] = 1;
}
int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		cin >> N;
		Level = N;
		arr.clear();
		visited.clear();
		completed.clear();
		arr.resize(N + 1, 0);
		visited.resize(N + 1, 0);
		completed.resize(N + 1, 0);

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 1)continue;
			dfs(i);

		}

		cout << Level << "\n";


	}

}
