#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Dong {
	int solnum;
	int year;
	string name;
};

bool cmp(Dong left, Dong right) {
	return left.solnum > right.solnum;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		int A, B;
		cin >> A >> B;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << "Material Management " << tc << endl;
		cout << "Classification ---- End!"<< endl;
	}
	return 0;
}