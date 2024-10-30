#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char*argv[]) {
	int N, K;
	cin >> N >> K;
	vector<int> A;
	vector<int> B;
	int mini = 2134567890;
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		mini = min(a, mini);
		maxi = max(b, maxi);
		A.push_back(a);
		B.push_back(b);
	}
	int left = 0;
	if (mini >= maxi) cout << 0;
	else {
		int right = maxi - mini;
		while (left < right) {
			long long mid = (left + right) / 2;
			int ans = 0;
			for (int i = 0; i < N; i++) {
				if (A[i] + mid >= B[i]) ans++;
			}
			if (ans >= K) right = mid;
			else left = mid + 1;
		}
		cout << right;
	}
	
	return 0;
}