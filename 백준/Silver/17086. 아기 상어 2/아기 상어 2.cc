#include<iostream>
#include<queue>

using namespace std;

int N,M;
int arr[51][51];
int visited[51][51];

int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,1,-1,-1,0,1};

queue<pair<int,int>>sharks;

void bfs(){
    
    while(!sharks.empty()){
        auto [cy,cx]=sharks.front();sharks.pop();
        int dist = visited[cy][cx] + 1;
        for(int i=0;i<8;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx <0 || ny >=N || nx >=M)continue;
            if(visited[ny][nx]<=dist)continue;
            visited[ny][nx] = dist;
            sharks.push({ny,nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            visited[i][j] = N*M+1;
            if(arr[i][j]==1){
                sharks.push({i,j});
                visited[i][j]=0;
            }
        }
    }
    
    bfs();
    
    
    int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==1)continue;
            if(visited[i][j]>answer)answer = visited[i][j];
        }
    }
    
    cout << answer;

}
