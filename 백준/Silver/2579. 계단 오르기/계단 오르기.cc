#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>st(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> st[i];

	}

	vector<int>dp(n+1);
	dp[0] = 0;
	dp[1] = st[1];
	dp[2] = dp[1]+st[2];
	dp[3] = st[3] + max(dp[1], st[2]);

	for (int i =4; i <= n; i++) {
		dp[i] = st[i] + max(st[i - 1] + dp[i - 3], dp[i - 2]);
	}
	cout << dp[n];
}