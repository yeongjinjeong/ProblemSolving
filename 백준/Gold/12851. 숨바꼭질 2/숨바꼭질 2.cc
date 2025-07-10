#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001];

struct Node {
    int ind;
    int time;
};

int main() {
    cin >> N >> K;
    fill(visited, visited + 100001, -1); // -1로 초기화
    queue<Node> q;
    q.push({N, 0});
    visited[N] = 0;

    int fastest = -1, cnt = 0;
    while (!q.empty()) {
        Node now = q.front(); q.pop();

        if (now.ind == K) {
            if (fastest == -1) {
                fastest = now.time;
                cnt = 1;
            } else if (fastest == now.time) {
                cnt++;
            }
            continue;
        }

        int nexttime = now.time + 1;
        for (int next : {now.ind - 1, now.ind + 1, now.ind * 2}) {
            if (next < 0 || next > 100000) continue;
            // 아직 방문 안 했거나, 같은 시간에 방문할 수 있으면 큐에 넣기
            if (visited[next] == -1 || visited[next] == nexttime) {
                visited[next] = nexttime;
                q.push({next, nexttime});
            }
        }
    }
    cout << fastest << "\n" << cnt;
}

