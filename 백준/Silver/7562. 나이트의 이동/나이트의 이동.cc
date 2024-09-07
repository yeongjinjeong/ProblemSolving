#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
int N;
vector<vector<int>>arr;

int ydir[8]={2,2,1,1,-1,-1,-2,-2};
int xdir[8]={1,-1,2,-2,2,-2,1,-1};

void bfs(int sy,int sx){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    arr[sy][sx]=0;
    while(!q.empty()){
        pair<int,int> now = q.front();q.pop();
        for(int d=0;d<8;d++){
            int ny = now.first + ydir[d];
            int nx = now.second + xdir[d];
            if(ny==sy && nx==sx)continue;
            if(ny<0 || nx<0|| ny>=N|| nx>=N)continue;
            if(arr[ny][nx]!=0)continue;
            arr[ny][nx]= arr[now.first][now.second]+1;
            q.push({ny,nx});
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int tc=0;tc<T;tc++){
        cin >> N;
        arr.clear();
        arr.resize(N,vector<int>(N,0));
        int sy,sx,ey,ex;
        cin >> sy >> sx;
        cin >> ey >> ex;
        bfs(sy,sx);
        cout << arr[ey][ex]<<"\n";
    }
}
