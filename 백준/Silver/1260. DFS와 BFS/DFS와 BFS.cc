#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int N,M,V;
vector<vector<int>>arr;
vector<int>visited[2];

void dfs(int start){
    cout << start <<' ';
    visited[0][start]=1;
    
    for(int i=0;i<arr[start].size();i++){
        int next = arr[start][i];
        if(visited[0][next]==1) continue;
        dfs(next);
    }
}
void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[1][start]=1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now <<' ';
        visited[1][now]=1;
        for(int i=0;i<arr[now].size();i++){
            int next = arr[now][i];
            if(visited[1][next]==1)continue;
            q.push(next);
            visited[1][next]=1;
            
        }
    }
}
int main() {
    cin >> N >> M >> V;
    arr.resize(N+1);
    visited[0].resize(N+1,0);
    visited[1].resize(N+1,0);
    for(int i=0;i<M;i++){
        int st,en;
        cin >> st >> en;
        arr[st].push_back(en);
        arr[en].push_back(st);
    }
    for(int i=0;i<N+1;i++){
        sort(arr[i].begin(),arr[i].end());
    }
    dfs(V);
    cout << "\n";
    bfs(V);
}

