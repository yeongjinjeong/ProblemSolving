#include<iostream>
#include<string>
#include<queue>

using namespace std;

char arr[601][601];

int N,M;
int visited[601][601]={0};

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int bfs(int sy, int sx){
    int answer = 0;
    queue<pair<int,int>>q;
    q.push({sy,sx});
    visited[sy][sx]=1;
    
    while(!q.empty()){
        auto [cy,cx] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx <0 || ny >= N || nx>=M)continue;
            if(arr[ny][nx]=='X')continue;
            if(visited[ny][nx]==1)continue;
            if(arr[ny][nx]=='P') answer+=1;
            q.push({ny,nx});
            visited[ny][nx]=1;
        }
        
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    int sy,sx;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            arr[i][j]=s[j];
            if(s[j]=='I'){
                sy=i;sx=j;
            }
        }
    }
    int answer = bfs(sy,sx);
    
    if(answer==0)cout << "TT";
    else cout << answer;
    
    
}
