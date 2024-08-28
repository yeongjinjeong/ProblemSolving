#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int T,N,M,K;
vector<vector<int>>arr;
int ydir[4]={1,-1,0,0};
int xdir[4]={0,0,-1,1};
int cnt;
void bfs(){
    int visited[50][50]={0};
    for(int i=0;i<N*M;i++){
        int y = i/M;
        int x = i%M;
        if(visited[y][x]==1)continue;
        if(arr[y][x]==0)continue;
        visited[y][x]=1;
        queue<pair<int,int>>q;
        q.push({y,x});
        while(!q.empty()){
            pair<int,int>now = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int ny = now.first + ydir[d];
                int nx = now.second + xdir[d];
                if(ny<0 || nx <0 || ny>=N || nx >= M)continue;
                if(visited[ny][nx]==1)continue;
                if(arr[ny][nx]==0)continue;
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
        
        cnt++;
//        cout << y <<' '<<x<<endl;

    }
}

int main() {
    int T;
    cin >>T;
    for(int tc=0;tc<T;tc++){
        cin >> M >> N >> K;
        arr.clear();
        cnt =0;
        for(int i=0;i<N;i++){
            arr.push_back(vector<int>(M));
            for(int j=0;j<M;j++){
                arr[i][j]=0;
            }
        }
        for(int i=0;i<K;i++){
            int x,y;
            cin >>x >>y;
            arr[y][x]=1;
        }
        bfs();
        cout << cnt << "\n";
        
    }
}
