#include<iostream>
#include<queue>

using namespace std;
int arr[101][101];
int N;
int maxh=0;
int maxcnt=0;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int bfs(int h){
    int visited[101][101]={0};
    int safeplace=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]<=h)continue;
            if(visited[i][j]==1)continue;
            queue<pair<int,int>>q;
            q.push({i,j});
            visited[i][j]=1;
            while(!q.empty()){
                pair<int,int>now = q.front();q.pop();
                for(int i=0;i<4;i++){
                    int ny = now.first + dy[i];
                    int nx = now.second + dx[i];
                    if(ny<0 || nx <0 || ny >=N || nx >= N)continue;
                    if(arr[ny][nx]<=h)continue;
                    if(visited[ny][nx]==1)continue;
                    visited[ny][nx]=1;
                    q.push({ny,nx});
                }
            }
            safeplace++;
            
        }
    }
    return safeplace;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]>maxh)maxh = arr[i][j];
        }
    }
    for(int i=0;i<=maxh;i++){
        int cnt = bfs(i);
        if(cnt > maxcnt)maxcnt=cnt;
    }
    cout << maxcnt;
    
    return 0;
}
