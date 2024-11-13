#include <iostream>
using namespace std;

int N, M;
int parent[500000];

int uFind(int a) {
	if (a == parent[a]) return a;
	else return uFind(parent[a]);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		a = uFind(a);
		b = uFind(b);
		if (a == b) {
			cout << i;
			return 0;
		}
		if (a < b) parent[b] = a;
		else parent[a] = b;
	}
	cout << 0;
	return 0;
}