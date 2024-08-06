#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n;
long long target;
void func(int now,int num) {
	if (now == n+1) {
		target = num;
		return;
	}
	for (long long i = num+1; i < 999999999; i++) {
		string s = to_string(i);
		if (s.find("666") != -1) {
			func(now + 1, i);
			break;
		}
	}
}
int main() {
	cin >> n;
	func(1, 0);
	
	cout << target;
}

