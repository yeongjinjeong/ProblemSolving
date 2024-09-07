#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

vector<string> arr;
int N, M;
int ydir[] = {1, -1, 0, 0};
int xdir[] = {0, 0, 1, -1};
vector<vector<int>> visited[2]; // visited[0]: 벽을 부수지 않고 방문, visited[1]: 벽을 부수고 방문

int bfs() {
    queue<tuple<int, int, int>> space;
    space.push({0, 0, 0}); // (y, x, 벽을 부쉈는지 여부)
    visited[0][0][0] = 1;  // 시작 지점 (0, 0)에서 벽을 부수지 않고 시작

    while (!space.empty()) {
        int y, x, broken;
        tie(y, x, broken) = space.front();
        space.pop();

        // 도착 지점에 도달한 경우
        if (y == N - 1 && x == M - 1) {
            return visited[broken][y][x];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + ydir[i];
            int nx = x + xdir[i];

            // 범위 체크
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            // 벽이 없는 곳으로 이동
            if (arr[ny][nx] == '0' && visited[broken][ny][nx] == 0) {
                visited[broken][ny][nx] = visited[broken][y][x] + 1;
                space.push({ny, nx, broken});
            }

            // 벽이 있는 곳으로 이동하고, 아직 벽을 부수지 않은 경우
            if (arr[ny][nx] == '1' && broken == 0 && visited[1][ny][nx] == 0) {
                visited[1][ny][nx] = visited[broken][y][x] + 1;
                space.push({ny, nx, 1});
            }
        }
    }

    return -1; // 도착할 수 없는 경우
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    arr.resize(N);
    visited[0].resize(N, vector<int>(M, 0));
    visited[1].resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int minPath = bfs();
    cout << minPath << endl;

    return 0;
}
