#include <iostream>
using namespace std;

int N;
int wcnt = 0;
int bcnt = 0;
int arr[128][128];

void dfs(int row, int col, int len) {
	if (len == 0) return;
	int gizun = arr[row][col];
	bool flag = false;
	for (int i = row; i < row + len; i++) {
		for (int j = col; j < col + len; j++) {
			if (arr[i][j] != gizun) flag = true;			
		}
	}
	if (flag) {
		dfs(row, col, len / 2);
		dfs(row + len / 2, col, len / 2);
		dfs(row, col + len / 2, len / 2);
		dfs(row + len / 2, col + len / 2, len / 2);
	}
	if (flag == false && gizun) bcnt++;
	if(flag == false && gizun == 0) wcnt++;
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