#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int N;
char arr[100][100]={0};
char arr2[100][100]={0}; //색약인 사람이 보이는 판
int ydir[4]={1,-1,0,0};
int xdir[4]={0,0,-1,1};
int cnt1=0;
int cnt2=0;
void bfs1(int N){
    int visited[100][100]={0};
    for(int i=0;i<N*N;i++){
        int y = i/N;
        int x = i%N;
        if(visited[y][x]==1)continue;
        if(arr[y][x]==0)continue;
        visited[y][x]=1;
        char target = arr[y][x];
        queue<pair<int,int>>q;
        q.push({y,x});
        while(!q.empty()){
            pair<int,int>now = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int ny = now.first + ydir[d];
                int nx = now.second + xdir[d];
                if(ny<0 || nx <0 || ny>=N || nx >= N)continue;
                if(visited[ny][nx]==1)continue;
                if(arr[ny][nx]!=target)continue;
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
        
        cnt1++;
//        cout << y <<' '<<x<<endl;

    }
}

void bfs2(int N){
    int visited[100][100]={0};
    for(int i=0;i<N*N;i++){
        int y = i/N;
        int x = i%N;
        if(visited[y][x]==1)continue;
        if(arr2[y][x]==0)continue;
        visited[y][x]=1;
        char target = arr2[y][x];
        queue<pair<int,int>>q;
        q.push({y,x});
        while(!q.empty()){
            pair<int,int>now = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int ny = now.first + ydir[d];
                int nx = now.second + xdir[d];
                if(ny<0 || nx <0 || ny>=N || nx >= N)continue;
                if(visited[ny][nx]==1)continue;
                if(arr2[ny][nx]!=target)continue;
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
        
        cnt2++;
//        cout << y <<' '<<x<<endl;

    }
}

int main() {
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        for(int j=0;j<N;j++){
            if(arr[i][j]=='G'){
                arr2[i][j]='R';
            }
            else arr2[i][j]= arr[i][j];
        }
    }
//    cout << endl;
//    for(int i=0;i<N;i++){
//        
//        for(int j=0;j<N;j++){
//            cout << arr[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for(int i=0;i<N;i++){
//        
//        for(int j=0;j<N;j++){
//            cout << arr2[i][j];
//        }
//        cout << endl;
//    }
    bfs1(N);
    bfs2(N);
    cout << cnt1 <<' ' << cnt2;
}
