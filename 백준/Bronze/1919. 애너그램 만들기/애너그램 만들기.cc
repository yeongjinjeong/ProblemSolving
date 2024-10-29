#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	string first;
	cin >> first;
	string secon;
	cin >> secon;
	int ans = 0;
	if (first.size() > secon.size()) {
		string temp;
		temp = first;
		first = secon;
		secon = temp;
	}
	int N = first.size();
	for (int i = 0; i < N; i++) {
		int idx = secon.find(first[0], 0);
		if (idx == -1) {
			first.erase(0, 1);
			ans += 1;
		}
		else {
			secon.erase(idx, 1);
			first.erase(0, 1);			
		}
	}
	ans += secon.size();
	
	cout << ans;
	return 0;
}