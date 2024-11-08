#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct Node {
	int row, col;
};

int N, ans;
int arr[100][100];
int dirr[] = { 1,-1,0,0 };
int dirc[] = { 0,0,1,-1 };

int calcul(int label) {
	int ansnum = 0;
	bool visit[100][100] = { false };
	queue<Node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == label) q.push({ i,j });
		}
	}
	visit[q.front().row][q.front().col] = true;
	while (!q.empty()) {
		int qnum = q.size();
		for (int i = 0; i < qnum; i++) {
			Node now = q.front();			
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nrow = now.row + dirr[dir];
				int ncol = now.col + dirc[dir];
				if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
				if (visit[nrow][ncol]) continue;
				if (arr[nrow][ncol] != 0 && arr[nrow][ncol] != label) {
					return ansnum;
				}
				visit[nrow][ncol] = true;
				if (arr[nrow][ncol] == 0) q.push({ nrow, ncol });
			}
		}
		ansnum++;
	}
}

int main() {
	cin >> N;	
	for (int i = 0; i < N; i++) {		
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) temp = -1;
			arr[i][j] = temp;
		}		
	}
	int label = 0;
	bool visit1[100][100] = { false };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == -1) {
				label++;
				queue<Node> q;
				q.push({ i,j });
				visit1[i][j] = true;
				arr[i][j] = label;
				while (!q.empty()) {
					Node now = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nrow = now.row + dirr[dir];
						int ncol = now.col + dirc[dir];
						if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N) continue;
						if (visit1[nrow][ncol]) continue;
						if (arr[nrow][ncol] == 0) continue;
						visit1[nrow][ncol] = true;
						arr[nrow][ncol] = label;
						q.push({ nrow, ncol });
					}
				}
			}
		}
	}
	ans = 2134567890;
	for (int i = 1; i <= label; i++) {
		int tempans = calcul(i);
		ans = min(ans, tempans);
	}
	cout << ans;

	return 0;
}