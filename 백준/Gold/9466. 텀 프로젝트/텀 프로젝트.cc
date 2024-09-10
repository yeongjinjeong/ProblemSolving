#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, visited, done;
int cnt;

void dfs(int x) {
    visited[x] = 1;
    int next = parent[x];
    
    if (!visited[next]) {
        dfs(next);
    } else if (!done[next]) {
        for (int i = next; i != x; i = parent[i]) cnt--;
        cnt--;
    }
    
    done[x] = 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        parent.resize(n + 1);
        visited.assign(n + 1, 0);
        done.assign(n + 1, 0);
        cnt = n;

        for (int i = 1; i <= n; i++) {
            cin >> parent[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
