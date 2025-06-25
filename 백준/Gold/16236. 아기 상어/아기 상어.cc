#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
int arr[21][21];

int sharky;
int sharkx;
int eat=0;
int sharksize=2;

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};


struct Node{
    int y;
    int x;
    int cost;
};

int findtarget(int sy,int sx){
    int visited[21][21]={0};
    queue<Node> q;
    q.push({sy,sx,0});
    visited[sy][sx]=1;
    Node target = {100,100,100000};
    while(!q.empty()){
        Node now = q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx >= N)continue;
            if(visited[ny][nx]==1)continue;
            if(arr[ny][nx]>sharksize)continue;
            else if(arr[ny][nx]<sharksize && arr[ny][nx]!=0){
                int ncost = now.cost + 1;
                if(ncost < target.cost) target = {ny,nx,ncost};
                else if(ncost == target.cost){
                    if(target.y > ny) target = {ny,nx,ncost};
                    else if(target.y == ny){
                        if(target.x > nx) target = {ny,nx,ncost};
                    }
                }
            }
            q.push({ny,nx,now.cost+1});
            visited[ny][nx] = 1;
        }
    }
    if(target.y==100){
        return 0;
    }
    eat++;
    if(eat==sharksize){
        sharksize++;
        eat =0;
    }
    arr[target.y][target.x]= 0;
    arr[sharky][sharkx] =0;
    sharky = target.y;
    sharkx = target.x;
    return target.cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                sharky = i;
                sharkx = j;
            }
            
        }
    }
    int time = 0;
    while(1){
        int res = findtarget(sharky,sharkx);
        if(res==0) break;
        time+=res;
    }
        
    cout << time;
}

