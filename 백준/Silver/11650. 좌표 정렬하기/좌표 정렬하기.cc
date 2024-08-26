#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int first, second;
};
bool cmp(Node left, Node right) {
	if (left.first < right.first) return true;
	if (left.first > right.first) return false;

	if (left.second < right.second) return true;
	if (left.second > right.second) return false;

	return false;
}
int main() {

	int N;
	cin >> N;

	vector<Node>arr;
	for (int i = 0; i < N; i++) {
		int x,y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << ' ' << arr[i].second << "\n";
	}
}