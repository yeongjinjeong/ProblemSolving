#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char gear[5][8];

void clockwise(int num) {
	char change[8];
	change[0] = gear[num][7];
	for (int i = 1; i < 8; i++) {
		change[i] = gear[num][i - 1];
	}
	for (int i = 0; i < 8; i++) {
		gear[num][i] = change[i];
	}
}
void counter(int num) {
	char change[8];
	change[7] = gear[num][0];
	for (int i = 0; i < 7; i++) {
		change[i] = gear[num][i + 1];
	}
	for (int i = 0; i < 8; i++) {
		gear[num][i] = change[i];
	}
}
int main() {
	int K;
	for (int i = 1; i < 5; i++) {
		cin >> gear[i];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		//회전 여부 확인
		int check[5][5] = { 0 };
		for (int j = 1; j < 4; j++) {
			if (gear[j][2] != gear[j + 1][6]) check[j][j + 1] = 1;
		}
		int num,dir;
		cin >> num >> dir;
		if (dir == 1) { //시계 방향일 때
			clockwise(num);
			//왼쪽 확인하고 돌리기
			for (int j = num; j > 1; j--) {
				if (check[j - 1][j] == 1) {
					//돌리는 것과 차이가 홀수면 다른 방향, 짝수면 같은 방향
					if ((num - (j - 1)) % 2 == 1) counter(j-1);
					else clockwise(j-1);
				}
				//안돌아가면 그 뒤에 것도 안돌아간다
				else break;
			}
			//오른쪽 확인하고 돌리기
			for (int j = num; j < 5; j++) {
				if (check[j][j+1] == 1) {
					//돌리는 것과 차이가 홀수면 다른 방향, 짝수면 같은 방향
					if (((j + 1) - num) % 2 == 1) counter(j+1);
					else clockwise(j+1);
				}
				//안돌아가면 그 뒤에 것도 안돌아간다
				else break;
			}

		}
		else if (dir == -1) { //반시계 방향일 때
			counter(num);
			for (int j = num; j > 1; j--) {
				if (check[j - 1][j] == 1) {
					if ((num - (j - 1)) % 2 == 1) clockwise(j-1);
					else counter(j-1);
				}
				else break;
			}
			for (int j = num; j < 5; j++) {
				if (check[j][j + 1] == 1) {
					if (((j + 1)-num) % 2 == 1) clockwise(j+1);
					else counter(j+1);
				}
				else break;
			}

		}
	}

	int score = 0;
	if (gear[1][0] == '1') score += 1;
	if (gear[2][0] == '1') score += 2;
	if (gear[3][0] == '1') score += 4;
	if (gear[4][0] == '1') score += 8;

	cout << score;

	return 0;
}