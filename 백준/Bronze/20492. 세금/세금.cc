#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int main() {
	int N;
	cin >> N;
	double res1 = N * (1 - 0.22);
	double res2 = N * 0.8 + N * 0.2 * (1 - 0.22);

	cout << (int)res1 <<' '<< (int)res2;
}