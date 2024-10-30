#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int K, N;
	cin >> K >> N;
	vector<int> v;
	int maxi = 0;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		if (maxi < temp) maxi = temp;
	}	
	long long left = 1;
	long long right = maxi;	
	while (left <= right)
	{
		long long mid = (left + right) / 2;		
		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += (v[i] / mid);			
		}
		if (N <= sum) left = mid + 1;
		else right = mid - 1;
	}		
	cout << right;
	
	return 0;
}