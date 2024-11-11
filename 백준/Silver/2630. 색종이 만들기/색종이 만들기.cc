#include <iostream>
using namespace std;

int N;
int wcnt = 0;
int bcnt = 0;
int arr[128][128];

void dfs(int row, int col, int len) {
	int gizun = arr[row][col];
	bool cut = false;
	for (int i = row; i < row + len; i++) {
		for (int j = col; j < col + len; j++) {
			if (arr[i][j] != gizun) cut = true;			
		}
	}
	if (cut) {
		dfs(row, col, len / 2);
		dfs(row + len / 2, col, len / 2);
		dfs(row, col + len / 2, len / 2);
		dfs(row + len / 2, col + len / 2, len / 2);
	}
	else {
		if (gizun) bcnt++;
		else wcnt++;
	}
}

int main() {	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, N);
	cout << wcnt << "\n" << bcnt;

	return 0;
}