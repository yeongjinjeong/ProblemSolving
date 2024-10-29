#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[]) {
	int M, N;
	cin >> M >> N;
	int num = M * N;
	int ans = 0;
	vector<vector<int>> arr;
	for (int i = 0; i < M; i++) {
		vector<int> temp(N);
		arr.push_back(temp);
	}
	arr[0][0] = 1;
	int cnt = M * N;
	cnt -= 1;
	int row = 0;
	int col = 0;
	int dir = 0;
	int dirr[] = { 0,1,0,-1 };
	int dirc[] = { 1,0,-1,0 };

	while(cnt) {
		int nrow = row + dirr[dir];
		int ncol = col + dirc[dir];
		if (nrow < 0 || ncol < 0 || nrow >= M || ncol >= N) {
			dir = (dir + 1) % 4;
			ans++;
			continue;
		}
		if (arr[nrow][ncol]) {
			dir = (dir + 1) % 4;
			ans++;
			continue;
		}
		arr[nrow][ncol] = 1;
		cnt--;
		row = nrow;
		col = ncol;
	}
	cout << ans;
	
	return 0;
}