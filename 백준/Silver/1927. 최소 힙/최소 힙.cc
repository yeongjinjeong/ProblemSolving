#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int, vector<int>, greater<int>>pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0 && pq.size() < 1) {
			cout << 0 << "\n";

		}
		else if (x == 0 && pq.size() >= 1) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else if (x > 0) {
			pq.push(x);
		}
	}

}