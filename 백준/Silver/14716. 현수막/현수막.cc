#include<iostream>
#include<queue>

using namespace std;

int arr[251][251];
int M,N;
int visited[251][251];

int dy[]={0,0,1,-1,1,-1,1,-1};
int dx[]={1,-1,0,0,1,1,-1,-1};

void bfs(int sy,int sx){
    queue<pair<int,int>>q;
    q.push({sy,sx});
    visited[sy][sx]=1;
    while(!q.empty()){
        auto [cy,cx]= q.front(); q.pop();
        for(int i=0;i<8;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || ny >=M || nx<0 || nx>=N)continue;
            if(arr[ny][nx]==0)continue;
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
    
    cin >> M >> N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    int answer = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0)continue;
            if(visited[i][j]==1)continue;
            bfs(i,j);
            answer++;
        }
    }
    
    cout << answer;

}
