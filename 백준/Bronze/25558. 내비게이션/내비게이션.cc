#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int row;
	int col;
};

struct fNode {
	int tc;
	long long ans;
};

bool cmp(fNode left, fNode right) {
	return left.ans < right.ans;
}

int main() {
	int N;
	cin >> N;
	int srow, scol, erow, ecol;
	cin >> srow >> scol >> erow >> ecol;
	vector<fNode> vv;
	for (int tc = 1; tc <= N; tc++) {
		int M;
		cin >> M;
		vector<Node> v;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		v.push_back({ erow, ecol });
		long long val = 0;
		int row = srow;
		int col = scol;
		for (int i = 0; i <= M; i++) {
			int ff = abs(row - v[i].row);
			int ss = abs(col - v[i].col);
			val += ff;
			val += ss;
			row = v[i].row;
			col = v[i].col;
		}
		vv.push_back({ tc, val });
	}
	sort(vv.begin(), vv.end(), cmp);
	cout << vv[0].tc;

	return 0;
}