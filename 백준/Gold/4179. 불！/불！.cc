#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int R, C;
vector<vector<char>> arr;
vector<vector<bool>> visited; // bool 타입으로 변경
queue<pair<int, int>> fire;
struct Ji {
    int x;
    int y;
    int cnt;
};
queue<Ji> ji;

int xd[] = {0, 0, 1, -1};
int yd[] = {1, -1, 0, 0};

int main() {
    cin >> R >> C;
    arr.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false)); // false로 초기화

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'F') fire.push({i, j});
            else if (arr[i][j] == 'J') {
                ji.push({i, j, 0});
                visited[i][j] = true; // 시작점 방문 처리
            }
        }
    }

    while (!ji.empty()) {
        // 불 먼저 이동
        int fire_size = fire.size();
        for (int i = 0; i < fire_size; i++) {
            pair<int, int> now = fire.front(); fire.pop();
            for (int d = 0; d < 4; d++) {
                int nx = now.first + xd[d];
                int ny = now.second + yd[d];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
                arr[nx][ny] = 'F';
                fire.push({nx, ny});
            }
        }

        // 지훈이 이동
        int ji_size = ji.size();
        for (int i = 0; i < ji_size; i++) {
            Ji nowJ = ji.front(); ji.pop();
            
            for (int d = 0; d < 4; d++) {
                int nx = nowJ.x + xd[d];
                int ny = nowJ.y + yd[d];
                int nc = nowJ.cnt + 1;
                
                // 탈출 성공
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    cout << nc;
                    return 0;
                }
                
                // 이미 방문했거나 이동할 수 없는 경우
                if (visited[nx][ny] || arr[nx][ny] == '#' || arr[nx][ny] == 'F') continue;
                
                visited[nx][ny] = true; // 방문 처리를 큐에 넣기 전에 수행
                ji.push({nx, ny, nc});
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
