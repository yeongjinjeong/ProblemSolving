#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, w, L;
int truck[1001];
int main() {
	cin >> n >> w >> L;
	int time=0;
	for (int i = 1; i <= n; i++) {
		cin >> truck[i];
	}
	queue<int>q;
	for (int i = 0; i < w; i++) {
		q.push(0);
	}
	int sum = 0;
	int ind = 1;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		sum -= num;
		time++;
		if (ind <=n && sum + truck[ind] <= L) {
			sum += truck[ind];
			q.push(truck[ind]);
			ind++;

		}
		else if (ind <= n && sum + truck[ind] > L) {
			q.push(0);
		}
	}
	cout << time;

}