#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
int N;
int arr[101][101] = { 0 }; //0: 빈칸, 1: 뱀, 2: 사과
int ydir[4] = { 0,1,0,-1 };
int xdir[4] = { 1,0,-1,0 };
queue<pair<int, int>>q;
deque<pair<int, int>>snake;

int main() {
    int K;
    cin >> N;
    cin >> K;
    //사과 좌표 입력
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        arr[y][x] = 2;
    }
    int L;
    cin >> L;
    int dirInd = L * 4;
    //방향을 큐에 넣기
    int pre=0;//이전 초 저장
    for (int i = 0; i < L; i++) {
        int num;
        char RL;
        cin >> num >> RL;
        for (int j = pre; j < num; j++) {
            q.push({ ydir[dirInd % 4],xdir[dirInd % 4] });

        }
        if (RL == 'D') dirInd++;
        else if (RL == 'L') dirInd--;
        pre = num;
    }
    q.push({ ydir[dirInd % 4],xdir[dirInd % 4] });
    
    snake.push_front({1,1});
    int flag = 0;
    int snakeY = 1;
    int snakeX = 1;
    int cnt = 0;
    pair<int, int>dir;
    while (!q.empty()) {
        cnt++;
        dir = q.front(); q.pop();
        int nextY = snakeY + dir.first;
        int nextX = snakeX + dir.second;
        if (nextY > N || nextY <= 0 || nextX > N || nextX <= 0|| arr[nextY][nextX] == 1) {
            flag = 1;
            break;
        }
        if (arr[nextY][nextX] == 2) {
            snake.push_front({ nextY,nextX });
            arr[nextY][nextX] = 1;
        }
        else {
            snake.push_front({ nextY,nextX });
            arr[nextY][nextX] = 1;
            int endY = (*snake.rbegin()).first;
            int endX = (*snake.rbegin()).second;
            arr[endY][endX] = 0;
            snake.pop_back();
        }
        snakeY = (*snake.begin()).first;
        snakeX = (*snake.begin()).second;
    }
    if (flag == 0) {
        while (1) {
            cnt++;
            int nextY = snakeY + dir.first;
            int nextX = snakeX + dir.second;
            if (nextY > N || nextY <= 0 || nextX > N || nextX <= 0 || arr[nextY][nextX] == 1) {
                flag = 1;
                break;
            }
            if (arr[nextY][nextX] == 2) {
                snake.push_front({ nextY,nextX });
                arr[nextY][nextX] = 1;
            }
            else {
                snake.push_front({ nextY,nextX });
                arr[nextY][nextX] = 1;
                int endY = (*snake.rbegin()).first;
                int endX = (*snake.rbegin()).second;
                arr[endY][endX] = 0;
                snake.pop_back();
            }
            snakeY = (*snake.begin()).first;
            snakeX = (*snake.begin()).second;
        }
    }

    cout << cnt;
}