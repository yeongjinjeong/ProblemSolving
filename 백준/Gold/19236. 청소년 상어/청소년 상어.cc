#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int row;
	int col;
	int dir;
	bool live;
};

int dirr[] = { -1,-1,0,1,1,1,0,-1 };
int dirc[] = { 0,-1,-1,-1,0,1,1,1 };
int ans;

/*
전략 수립하는 메모장
*/

void dfs(int arr[4][4], Node mulko[17], int row, int col, int sum) {
	int copy_arr[4][4];
	Node copy_mulko[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		copy_mulko[i] = mulko[i];
	}
	int fish = copy_arr[row][col];
	int dir = copy_mulko[fish].dir;
	copy_mulko[fish].live = false;
	copy_arr[row][col] = 0;

	sum += fish;
	if (ans < sum) ans = sum;

	for (int i = 1; i <= 16; i++) {
		if (copy_mulko[i].live == false) continue;
	
		int frow = copy_mulko[i].row;
		int fcol = copy_mulko[i].col;
		int fdir = copy_mulko[i].dir;

		int nrow = frow + dirr[fdir];
		int ncol = fcol + dirc[fdir];		
		
		while (nrow < 0 || ncol < 0 || nrow >= 4 || ncol >= 4 ||
			(nrow == row && ncol == col)) {			  
			fdir = (fdir + 1) % 8;
			nrow = frow + dirr[fdir];
			ncol = fcol + dirc[fdir];
		}

		copy_mulko[i].row = nrow;
		copy_mulko[i].col = ncol;
		copy_mulko[i].dir = fdir;		
		if (copy_arr[nrow][ncol] != 0) {
			int targetFish = copy_arr[nrow][ncol];		
			copy_mulko[targetFish].row = frow;
			copy_mulko[targetFish].col = fcol;												
			copy_arr[frow][fcol] = targetFish;
		}
		else copy_arr[frow][fcol] = 0;

		copy_arr[nrow][ncol] = i;
	}
	
	int nrow = row;
	int ncol = col;
	while(1) {
		nrow += dirr[dir];
		ncol += dirc[dir];
		if (nrow < 0 || nrow >= 4 || ncol < 0 || ncol >= 4) break;
		if (copy_arr[nrow][ncol]) dfs(copy_arr, copy_mulko, nrow, ncol, sum);		
	}
}

int main() {
	int arr[4][4];
	Node mulko[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			arr[i][j] = a;
			mulko[a] = { i,j,b-1,true };
		}
	}
	ans = 0;
	dfs(arr, mulko, 0, 0, 0);
	cout << ans;

	return 0;
}