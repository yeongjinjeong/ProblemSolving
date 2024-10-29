#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int tc;
	long long ans;
};

bool cmp(Node left, Node right) {
	return left.ans < right.ans;
}

int main() {
	int N;
	cin >> N;
	int srow, scol, erow, ecol;
	cin >> srow >> scol >> erow >> ecol;
	vector<Node> v;
	for (int tc = 1; tc <= N; tc++) {
		int M;
		cin >> M;
		long long val = 0;
		int row = srow;
		int col = scol;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			int ff = abs(row - a);
			int ss = abs(col - b);
			val += ff;
			val += ss;
			row = a;
			col = b;				
		}
		int ff = abs(row - erow);
		int ss = abs(col - ecol);
		val += ff;
		val += ss;		
		v.push_back({ tc, val });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].tc;

	return 0;
}

//냅색, 그리디, DP, 이분탐색