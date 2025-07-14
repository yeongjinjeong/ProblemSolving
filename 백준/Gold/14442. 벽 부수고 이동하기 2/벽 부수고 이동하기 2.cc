#include<iostream>
#include<queue>
#include<string>

using namespace std;

int N,M,K;
char arr[1001][1001];
int visited[1001][1001][11]={0};

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

struct Node{
    int y;
    int x;
    int cost;
    int cnt;
};

int bfs(){
    queue<Node>q;
    q.push({1,1,1,0});
    visited[1][1][0]=1;
    
    while(!q.empty()){
        auto [cy,cx,ccost,ccnt] = q.front();q.pop();
        if(cy==N && cx==M){
            return ccost;
        }
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int ncost = ccost + 1;
            int ncnt = ccnt;
            if(ny<1 || nx<1 || ny>N || nx>M) continue;
            
            if(ccnt>=K && arr[ny][nx]=='1')continue;
            else if(ccnt<K && arr[ny][nx]=='1') ncnt++;
            
            if(visited[ny][nx][ncnt]==1)continue;
            visited[ny][nx][ncnt]=1;
            q.push({ny,nx,ncost,ncnt});
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        string s;
        cin >> s;
        
        for(int j=1;j<=M;j++){
            arr[i][j]=s[j-1];
        }
    }
    

    int answer=bfs();
    
    cout << answer;
    
}


