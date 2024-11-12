#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M;
unordered_map<string, int> um;
vector<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;	
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;		
		um[temp] = 0;
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (um.find(temp) == um.end()) continue;
		else ans.push_back(temp);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}