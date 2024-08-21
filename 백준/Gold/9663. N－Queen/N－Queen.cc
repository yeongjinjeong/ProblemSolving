#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int group1[20][20]; //미리 Queen의 방향을 매핑하기 위한 용도
				   //좌하 방향
int n;
int dat_col[40]; // 수직 - index: col, value: 사용여부
int dat1[100]; //좌하 - index: 좌하, value: 사용여부
int dat2[100]; //우하 - index: 우하, value: 사용여부


void make_group1(int r, int c) {
	int R = r;
	int C = c;
	while (1) {
		if (R >= n || C < 0) return;
		group1[R][C] = R + C;
		R += 1;
		C -= 1;
	}
}
int group2[20][20]; //미리 Queen의 방향을 매핑하기 위한 용도
					//우하 방향

void make_group2(int r, int c) {
	int R = r;
	int C = c;
	while (1) {
		if (R >= n || C < 0) return;
		group2[R][C] = R - C + n;
		R += 1;
		C -= 1;
	}
}

int answer=0;

void func(int row) {
	if (row >= n) {
		answer++;
		return;
	}
	for (int col = 0; col < n; col++) {
		
		if (dat_col[col] == 1 || dat1[group1[row][col]] == 1 || dat2[group2[row][col]] == 1)
			continue;
		dat_col[col] = 1;
		dat1[group1[row][col]] = 1;
		dat2[group2[row][col]] = 1;

		func(row + 1);
		dat_col[col] = 0;
		dat1[group1[row][col]] = 0;
		dat2[group2[row][col]] = 0;
	}
}

int main() {
	cin >> n;

	for(int r=0;r<n;r++){
		for (int c = 0; c < n; c++) {
			if (group1[r][c] == 0) {
				make_group1(r, c);
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << group1[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (group2[r][c] == 0) {
				make_group2(r, c);
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << group2[i][j];
		}
		cout << endl;
	}*/
	func(0);

	cout << answer;

	return 0;
}