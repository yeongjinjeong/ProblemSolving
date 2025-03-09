#include<iostream>
#include<unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	unordered_set<int>s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (s.find(num) == s.end()) {
			cout << 0 << "\n";
		}
		else cout << 1 << "\n";
	}
}