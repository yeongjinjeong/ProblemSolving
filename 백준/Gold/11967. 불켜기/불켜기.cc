#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N,M;
struct Node{
    int light = 0;
    vector<pair<int,int>>room;
};

Node arr[101][101];
int visited[101][101]={0};

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int answer = 1;


void bfs(){
    queue<pair<int,int>>q;
    q.push({1,1});
    visited[1][1]=1;
    while(!q.empty()){
        pair<int,int>now = q.front(); q.pop();
        for(int i=0;i<arr[now.first][now.second].room.size();i++){
            int y = arr[now.first][now.second].room[i].first;
            int x = arr[now.first][now.second].room[i].second;
            if(arr[y][x].light==1)continue;
            arr[y][x].light = 1;
            //cout << y << "," << x <<endl;
            for(int a=1;a<=N;a++){
                for(int b=1;b<=N;b++){
                    visited[a][b]=0;
                }
            }
            answer += 1;
        }
        for(int i=0;i<4;i++){
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny<1 || nx <1 || ny > N || nx>N)continue;
            if(arr[ny][nx].light==0)continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    arr[1][1].light = 1;
    
    for(int i=0;i<M;i++){
        int y,x,ry,rx;
        cin >> y >> x >> ry >> rx;
        arr[y][x].room.push_back({ry,rx});
    }
    bfs();
    cout << answer;
}
