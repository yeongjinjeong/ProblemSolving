#include <iostream>
#include <queue>
using namespace std;

int N, M, ans;
int arr[1000][1000];
bool visited[1000][1000];
int dirr[] = { -1,1,0,0 };
int dirc[] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				visited[i][j] = true;
				q.push({ i,j });				
			}
		}
	}
	while (1) {
		int dongi = q.size();
		for (int i = 0; i < dongi; i++) {
			int nowrow = q.front().first;
			int nowcol = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nrow = nowrow + dirr[dir];
				int ncol = nowcol + dirc[dir];
				if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= M) continue;
				if (visited[nrow][ncol]) continue;
				if (arr[nrow][ncol] != 0) continue;
				arr[nrow][ncol] = 1;
				visited[nrow][ncol] = true;
				q.push({ nrow, ncol });
			}
		}
		ans++;
		if (q.empty()) break;
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) flag = true;
		}
	}
	if (flag) cout << -1;
	else cout << ans - 1;

	return 0;
}