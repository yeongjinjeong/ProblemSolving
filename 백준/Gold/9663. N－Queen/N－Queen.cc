#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int visit1[15];
int visit2[30];
int visit3[30];

void dfs(int now) {
	if (now == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit1[i] == 1 || visit2[i + now] == 1 || visit3[now - i + N - 1] == 1) continue;
		visit1[i] = 1;
		visit2[i + now] = 1;
		visit3[now - i + N - 1] = 1;
		dfs(now + 1);
		visit1[i] = 0;
		visit2[i + now] = 0;
		visit3[now - i + N - 1] = 0;
	}
}

int main() {
	cin >> N;	
	ans = 0;
	dfs(0);
	cout << ans;

	return 0;
}