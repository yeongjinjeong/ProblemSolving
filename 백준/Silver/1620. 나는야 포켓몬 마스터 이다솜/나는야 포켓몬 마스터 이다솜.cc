#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int N, M;
unordered_map<string, int> um;
vector<string> dougam;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	dougam.push_back("dummy");
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		dougam.push_back(temp);
		um[temp] = i;
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if ('0' <= temp[0] && temp[0] <= '9') {
			int t1 = stoi(temp);
			cout << dougam[t1] << "\n";
		}
		else cout << um[temp] << "\n";
	}
	return 0;
}