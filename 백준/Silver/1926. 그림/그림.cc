#include<iostream>
#include<queue>


using namespace std;

int arr[501][501];
int n,m;
int maxarea=0;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int picture = 0;
int visited[501][501]={0};

int bfs(int sy,int sx){
    
    visited[sy][sx]=1;
    queue<pair<int,int>>q;
    q.push({sy,sx});
    int cnt = 1;
    while(!q.empty()){
        pair<int,int>now = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(arr[ny][nx]==0)continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;
            cnt++;
            q.push({ny,nx});
        }
    }
    picture++;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0)continue;
            if(visited[i][j]==1)continue;
            int area = bfs(i,j);
            if(area > maxarea)maxarea = area;
        }
    }
    cout << picture << "\n"<< maxarea;
    
}
