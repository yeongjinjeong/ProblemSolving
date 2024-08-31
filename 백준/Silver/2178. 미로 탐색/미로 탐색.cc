#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int N,M;
vector<string>arr;
vector<vector<int>>visited;
int cnt=0;
int ydir[4]={1,-1,0,0};
int xdir[4]={0,0,1,-1};

void bfs(){
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        pair<int,int> now = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = now.first + ydir[i];
            int nx = now.second + xdir[i];
            if(ny<0 || nx <0 || ny>=N || nx >=M)continue;
            if(visited[ny][nx]!=0) continue;
            if(arr[ny][nx]=='0')continue;
            visited[ny][nx]= visited[now.first][now.second] + 1;
            q.push({ny,nx});
        }
    }
    
}


int main(){
    cin >> N >> M;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
        visited.push_back(vector<int>(M,0));
    }
    bfs();
    cout << visited[N-1][M-1];
}
