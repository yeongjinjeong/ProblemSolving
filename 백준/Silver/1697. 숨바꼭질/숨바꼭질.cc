#include <iostream>
#include <vector>

using namespace std;

int N, K;
int minTime = 100000;
vector<int>dp(100000);

int main() {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		dp[i] = N - i;
	}
	dp[N] = 0;
	for (int i = N+1; i <= K+1; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
		if (i%2==0 && dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
		}
	}

	cout << dp[K];

	return 0;
}