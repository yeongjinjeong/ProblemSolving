#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int>F(N+1);
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < N + 1; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	cout << F[N];

	return 0;
}