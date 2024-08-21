#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Meeting {
	int start;
	int end;

};

bool cmp(Meeting left, Meeting right) {
	if (left.end < right.end) return true;
	if (left.end > right.end) return false;

	if (left.start < right.start) return true;
	if (left.start > right.start) return false;

	return false;
}
int main() {

	int N;
	cin >> N;
	vector<Meeting>time(N);

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		time[i] = { s,e };
	}

	sort(time.begin(), time.end(), cmp);

	int cnt = 1;
	int last = time[0].end;

	for (int i = 1; i < time.size(); i++) {
		if (time[i].start >= last) {
			cnt++;
			last = time[i].end;
		}
	}
	cout << cnt;
}