#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, L, R;
int arr[50][50];
bool visited[50][50];
int dirr[] = { -1,1,0,0 };
int dirc[] = { 0,0,-1,1 };

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	queue<pair<int, int>> q;
	while (1) {				
		bool stop = true;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {			
				if (visited[i][j]) continue;
				vector<pair<int, int>> v;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					int row = q.front().first;
					int col = q.front().second;
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nrow = row + dirr[dir];
						int ncol = col + dirc[dir];
						if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
						if (visited[nrow][ncol]) continue;
						int t1 = abs(arr[row][col] - arr[nrow][ncol]);
						if (L <= t1 && t1 <= R) {
							visited[nrow][ncol] = true;
							v.push_back({ nrow, ncol });
							q.push({ nrow, ncol });
							stop = false;
						}
					}
				}
				if (v.size()) {
					v.push_back({ i,j });
					int sum = 0;
					for (int i = 0; i < v.size(); i++) {
						sum += arr[v[i].first][v[i].second];
					}
					sum /= v.size();
					for (int i = 0; i < v.size(); i++) {
						arr[v[i].first][v[i].second] = sum;
					}					
				}				
			}
		}
		if (stop) {
			cout << ans;
			return 0;
		}
		ans++;
	}
	
	return 0;
}