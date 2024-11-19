#include <iostream>
#include <vector>
using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	vector<int> v;
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	int idx = -1;
	while (v.size()) {
		idx = (idx + K) % v.size();
		ans.push_back(v[idx]);
		v.erase(v.begin() + idx);
		idx -= 1;
	}
	cout << "<";
	for (int i = 0; i < ans.size(); i++) {
		
		if (i == ans.size() - 1) cout << ans[i] << ">";
		else cout << ans[i] << ", ";
	}
	return 0;
}