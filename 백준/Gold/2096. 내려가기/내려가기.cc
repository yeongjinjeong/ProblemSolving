#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
struct Score {
	int high;
	int low;
};

Score pre[3];
Score post[3];


int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < 3; i++) {
		pre[i] = { 0,0 };
	}
	for (int i = 1; i <= N; i++) {
		int f, s, t;
		cin >> f >> s >> t;
		post[0].high = f + max(pre[0].high, pre[1].high);
		post[1].high = s + max(max(pre[0].high, pre[1].high), pre[2].high);
		post[2].high = t + max(pre[2].high, pre[1].high);

		post[0].low = f + min(pre[0].low, pre[1].low);
		post[1].low = s + min(min(pre[0].low, pre[1].low), pre[2].low);
		post[2].low = t + min(pre[2].low, pre[1].low);

		for (int j = 0; j < 3; j++) {
			pre[j] = post[j];
		}
	}
	
	int maxN= max(max(pre[0].high, pre[1].high), pre[2].high);
	int minN= min(min(pre[0].low, pre[1].low), pre[2].low);
	cout << maxN << ' ' << minN;

}

