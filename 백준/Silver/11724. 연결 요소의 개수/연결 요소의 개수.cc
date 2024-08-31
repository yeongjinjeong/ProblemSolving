#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int N,M;
vector<vector<int>>arr;
int visited[1001]={0};
int cnt=0;

void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start] =1;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i=0;i<arr[now].size();i++){
            int next = arr[now][i];
            if(visited[next]==1) continue;
            q.push(next);
            visited[next]=1;
        }
    }
    cnt++;
}


int main(){
    cin >> N >> M;
    arr.resize(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        
    }
    for(int i=1;i<N+1;i++){
        if(visited[i]==1) continue;
        
        bfs(i);
    }
    cout << cnt;
}
