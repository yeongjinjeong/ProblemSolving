#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	unordered_map<int, int>m;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		m[num] += 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		cout << m[num] << " ";
	}
}