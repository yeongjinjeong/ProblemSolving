#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int w,h;
int answer;
int dy[]={0,0,1,-1,1,1,-1,-1};
int dx[]={1,-1,0,0,1,-1,1,-1};

vector<vector<int>>arr;
vector<vector<int>>visited;


void bfs(int sy,int sx){
    visited[sy][sx]=1;
    queue<pair<int,int>>q;
    q.push({sy,sx});
    
    while(!q.empty()){
        pair<int,int> now = q.front();q.pop();
        for(int i=0;i<8;i++){
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            
            if(ny<0||nx<0||ny>=h||nx>=w)continue;
            if(visited[ny][nx]==1)continue;
            if(arr[ny][nx]==0)continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
        }
    }
    answer++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(true){
        cin >> w >> h;
        answer = 0;
        if(w==0 && h==0)break;
        
        arr.clear();
        arr.resize(h,vector<int>(w));
        
        visited.clear();
        visited.resize(h,vector<int>(w,0));
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(visited[i][j]==1)continue;
                if(arr[i][j]==0)continue;
                bfs(i,j);
            }
        }
        cout << answer <<"\n";
        
        
        
    }
}
