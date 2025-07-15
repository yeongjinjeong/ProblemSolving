#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N,M;
char arr[1001][1001];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int visited[1001][1001]={0};
int answer[1000001]={0};

struct Node{
    int y,x,ind;
};

void bfs(int sy,int sx,int num){
    int cnt = 1;
    queue<Node>q;
    q.push({sy,sx,num});
    visited[sy][sx]=num;
    while(!q.empty()){
        auto [cy,cx,cind]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M)continue;
            if(arr[ny][nx]=='1')continue;
            if(visited[ny][nx]!=0)continue;
            visited[ny][nx]=num;
            q.push({ny,nx,num});
            cnt++;
        }
    }
    answer[num]=cnt;
    return;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >>M;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            arr[i][j]=s[j];
        }
    }
    
    int num=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='1')continue;
            if(visited[i][j]!=0)continue;
            bfs(i,j,num);
            num++;
        }
        
    }
//    cout<<endl;
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << visited[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='0') cout<< '0';
            else if(arr[i][j]=='1'){
                int li[4]={-1,-1,-1,-1};
                for(int d=0;d<4;d++){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(ny<0 || nx<0 || ny>=N || nx>=M)continue;
                    if(arr[ny][nx]=='1')continue;
                    bool check = false;
                    for(int k=0;k<4;k++){
                        if(visited[ny][nx]==li[k])check=true;
                    }
                    if(!check)li[d]=visited[ny][nx];
                }
                int result=1;
                for(int k=0;k<4;k++){
                    if(li[k]==-1)continue;
                    result += answer[li[k]];
                }
                cout << result%10;
            }
        }
        cout << "\n";
    }
}
