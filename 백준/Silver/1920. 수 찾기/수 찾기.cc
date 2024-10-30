#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;
		int left = 0;
		int right = N - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (v[mid] == target)
			{
				cout << 1 << "\n";
				break;
			}
			if (v[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		if (right < left) cout << 0 << "\n";
	}
	return 0;
}