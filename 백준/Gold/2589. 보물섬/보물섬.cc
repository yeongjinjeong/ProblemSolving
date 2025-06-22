#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
int N,M;
char arr[51][51];
int answer=0;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void bfs(int n, int r){
    int visited[51][51]={0};
    int maxcost=0;
    struct Node{
        int y;
        int x;
        int cost;
    };
    queue<Node> q;
    q.push({n,r,0});
    visited[n][r]=1;
    while(!q.empty()){
        Node now = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = now.y +dy[i];
            int nx = now.x + dx[i];
            if(ny < 0 || nx <0|| ny >= N || nx >= M)continue;
            if(arr[ny][nx]=='W')continue;
            if(visited[ny][nx]==1)continue;
            q.push({ny,nx,now.cost+1});
            visited[ny][nx]=1;
            if(maxcost < now.cost+1)maxcost = now.cost+1;
        }
        
    }
    if(answer < maxcost)answer=maxcost;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        for(int j=0;j<M;j++){
            arr[i][j]=input[j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='W')continue;
            bfs(i,j);
        }
    }
    
    cout << answer;
    
    return 0;
    
}

