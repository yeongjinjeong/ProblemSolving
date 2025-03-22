#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int R,C;
vector<vector<char>>arr;
vector<vector<bool>>visited;
queue<pair<int,int>>fire;
struct Ji{
    int x;
    int y;
    int cnt;
};
queue<Ji>ji;

int xd[] = {0,0,1,-1};
int yd[] = {1,-1,0,0};

int main(){
    cin >> R >> C;
    arr.resize(R,vector<char>(C));
    visited.resize(R,vector<bool>(C,false));

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='F') fire.push({i,j});
            else if(arr[i][j]=='J') {
                ji.push({i,j,0});
                visited[i][j] = true;
            }
        }
    }
    while(!ji.empty()){
        
        //불 먼저 이동
        
        int qsize = fire.size();
        for(int i=0;i<qsize;i++){
            pair<int,int> now = fire.front(); fire.pop();
            //cout << "fire" << now.first <<',' << now.second <<endl;
            for(int d=0;d<4;d++){
                int nx = now.first + xd[d];
                int ny = now.second + yd[d];
                if(nx <0 || ny < 0 || nx >=R || ny >= C) continue;
                if(arr[nx][ny] == '#')continue;
                if(arr[nx][ny]=='F')continue;
                arr[nx][ny] = 'F';
                fire.push({nx,ny});
            }
        }
    
        //지훈이 이동
        int jsize = ji.size();
        for(int i=0;i<jsize;i++){
            Ji nowJ = ji.front(); ji.pop();
            
            for(int d=0;d<4;d++){
                int nx = nowJ.x + xd[d];
                int ny = nowJ.y + yd[d];
                int nc = nowJ.cnt + 1;
                //cout << nx <<' ' << ny <<' ' << nc << endl;
                if(nx <0 || ny < 0 || nx >=R || ny >= C){
                    cout << nc;
                    return 0;
                }
                if(visited[nx][ny]==true)continue;
                if(arr[nx][ny] == '#')continue;
                if(arr[nx][ny]=='F')continue;
                visited[nx][ny] = true;
                ji.push({nx,ny,nc});
                
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
    
}
