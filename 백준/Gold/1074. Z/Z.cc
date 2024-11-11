#include <iostream>
using namespace std;

int N;
int trow, tcol, ans;
bool flag;

void dfs(int row, int col, int len) {
	if (flag) return;
	if (row == trow && col == tcol) {
		cout << ans;		
		flag = true;
		return;
	}
	if (row <= trow && trow < row + len && col <= tcol && tcol < col + len) {
		dfs(row, col, len / 2);
		dfs(row, col + len / 2, len / 2);
		dfs(row + len / 2, col, len / 2);
		dfs(row + len / 2, col + len / 2, len / 2);
	}
	else ans += (len*len);
}

int main() {		
	cin >> N >> trow >> tcol;
	ans = 0;
	flag = false;
	dfs(0, 0, 1<<N);

	return 0;
}