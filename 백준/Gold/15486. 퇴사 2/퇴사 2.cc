#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1500011] = { 0 };
int main() {
	int N;
	cin >> N;
	int maxProfit = 0;
	vector<pair<int, int>>arr;
	for (int i = 0; i < N ; i++) {
		int day, profit;
		cin >> day >> profit;
		arr.push_back({ day,profit });
	}
	arr.push_back({ 0,0 });

	for (int i = 1; i <= N+1; i++) {
		
		maxProfit = max(maxProfit, dp[i]);
		if (i + arr[i-1].first > N + 1) continue;
		dp[i + arr[i-1].first] = max(dp[i + arr[i-1].first], maxProfit + arr[i-1].second);
	}
	cout << maxProfit;
}