#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;
	vector<int> home;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		home.push_back(temp);
	}
	sort(home.begin(), home.end());
	int left = 1;
	int right = home[N - 1];
	while (left < right) {
		int mid = (left + right) / 2;
		int sum = home[0];
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (sum + mid < home[i]) {
				sum = home[i];
				cnt++;
			}
		}
		if (cnt < C) right = mid;
		else left = mid + 1;
	}
	cout << right;
	return 0;
}