#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<pair<int,int>>F(N+1);
	F[0] = { 1,0 };
	F[1] = { 0,1 };
	for (int i = 2; i < N + 1; i++) {
		F[i] = {F[i - 1].first + F[i - 2].first, F[i - 1].second + F[i - 2].second};
	}

	cout << F[N].first <<' '<<F[N].second;

	return 0;
}