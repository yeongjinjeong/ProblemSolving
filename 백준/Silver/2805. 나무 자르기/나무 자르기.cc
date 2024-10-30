#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> tree;
	int right = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (right < temp) right = temp;
		tree.push_back(temp);
	}
	int left = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if(tree[i] > mid) sum += (tree[i] - mid);
			if (sum > M) break;
		}
		if (sum == M)
		{
			cout << mid;
			return 0;
		}
		if (M < sum) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;

	return 0;
}