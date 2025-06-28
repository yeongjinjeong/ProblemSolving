#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int M,N,K;
int arr[101][101]={0};
int visited[101][101]={0};
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int bfs(int sy, int sx){
    queue<pair<int,int>>q;
    visited[sy][sx]=1;
    q.push({sy,sx});
    int cnt = 1;
    while(!q.empty()){
        pair<int,int>now = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny<0 || nx<0 || ny>=M || nx>=N)continue;
            if(arr[ny][nx]==1)continue;
            if(visited[ny][nx]==1)continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N >> K;
    for(int i=0;i<K;i++){
        int sy,sx,ey,ex;
        cin >> sx >> sy >> ex >> ey;
        for(int y=sy;y<ey;y++){
            for(int x=sx;x<ex;x++){
                arr[y][x]=1;
            }
        }
    }
    
    
    vector<int>areas;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==1)continue;
            if(arr[i][j]==1)continue;
            int area = bfs(i,j);
            areas.push_back(area);
        }
    }
    sort(areas.begin(),areas.end());
    
    cout << areas.size() << "\n";
    
    for(int i=0;i<areas.size();i++){
        cout << areas[i] << " ";
    }
    
}
