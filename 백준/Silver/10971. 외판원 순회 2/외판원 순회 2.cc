#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>arr;
int dat[11] = { 0 };
int N;
int dist = 0;
int cnt = 0;
int mindistance = 99999999;
void dfs(int node) {
	if (dat[0] == 1) {

		if (cnt == N && dist < mindistance) {
			mindistance = dist;
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (arr[node][i] == 0) continue;
		if (dat[i] == 1)continue;
		cnt++;
		dat[i] = 1;
		dist += arr[node][i];
		dfs(i);
		cnt--;
		dat[i] = 0;
		dist -= arr[node][i];


	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr.push_back(vector<int>(N));
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}

	dfs(0);

	cout << mindistance << "\n";


}