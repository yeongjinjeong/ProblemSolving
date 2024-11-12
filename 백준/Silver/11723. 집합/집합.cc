#include <iostream>
#include <string>
using namespace std;

int M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int S = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string temp1;
		int temp2;
		cin >> temp1;
		if (temp1 == "add") {
			cin >> temp2;
			S |= (1 << temp2);
		}
		else if (temp1 == "remove") {
			cin >> temp2;
			S &= ~(1 << temp2);
		}
		else if (temp1 == "check") {
			cin >> temp2;
			if (S & (1 << temp2)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (temp1 == "toggle") {
			cin >> temp2;
			if (S & (1 << temp2)) {
				S &= ~(1 << temp2);
			}
			else {             
				S |= (1 << temp2);
			}
		}
		else if (temp1 == "all") S = (1 << 21) - 1;
		else if (temp1 == "empty") S = 0;		
	}

	return 0;
}