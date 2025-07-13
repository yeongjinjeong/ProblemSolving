
#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int arr[201][201];
bool visited[201][201][31];

struct Node {
    int y, x, cnt, cost;
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs() {
    queue<Node> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node now = q.front(); q.pop();

        if (now.y == H - 1 && now.x == W - 1)
            return now.cost;

        
        if (now.cnt < K) {
            for (int i = 0; i < 8; i++) {
                int ny = now.y + hy[i];
                int nx = now.x + hx[i];
                int ncnt = now.cnt + 1;
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (arr[ny][nx] == 1) continue;
                if (visited[ny][nx][ncnt]) continue;
                visited[ny][nx][ncnt] = true;
                q.push({ny, nx, ncnt, now.cost + 1});
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            int ncnt = now.cnt;
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (arr[ny][nx] == 1) continue;
            if (visited[ny][nx][ncnt]) continue;
            visited[ny][nx][ncnt] = true;
            q.push({ny, nx, ncnt, now.cost + 1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> arr[i][j];

    cout << bfs();
    return 0;
}
