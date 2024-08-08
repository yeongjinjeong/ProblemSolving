#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		string newStr="";
		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < n; k++) {
				newStr += str[j];
			}
		}
		cout << newStr << "\n";
	}
}