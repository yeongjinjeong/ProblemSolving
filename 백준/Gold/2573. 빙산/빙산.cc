#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
int arr[300][300];
int ice=0;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
vector<vector<int>>visited;


void melt(){
    int next[300][300];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==0)next[i][j]=0;
            else{
                int water=0;
                for(int d=0;d<4;d++){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(ny<0 || nx<0 || ny>=N || nx >=M)continue;
                    if(arr[ny][nx]==0)water++;
                }
                next[i][j]= max(0,arr[i][j]-water);
                if(next[i][j]==0)ice--;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
         //   cout << next[i][j]<<" ";
            arr[i][j]=next[i][j];
        }
       // cout << endl;
    }
    
}
void bfs(int sy,int sx){
    visited[sy][sx]=1;
    queue<pair<int,int>>q;
    q.push({sy,sx});
    while(!q.empty()){
        pair<int,int>now = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx >=M)continue;
            if(arr[ny][nx]==0)continue;
            if(visited[ny][nx]==1)continue;
            q.push({ny,nx});
            visited[ny][nx]=1;
            
        }
    }
    
}
bool check(){
    visited.clear();
    visited.resize(N,vector<int>(M,0));
    int loaf = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==0)continue;
            if(visited[i][j]==1)continue;
            bfs(i,j);
            loaf++;
        }
    }
    
    if(loaf >=2 )return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]!=0)ice++;
        }
    }
    int answer=0;
    while(ice!=0){
        melt();
        answer++;
        if(ice==0){
            answer=0;
        }
        if(check())break;
        
    }
    cout << answer;
}
