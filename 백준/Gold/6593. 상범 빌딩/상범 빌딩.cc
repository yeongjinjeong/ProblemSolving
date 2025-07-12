#include<iostream>
#include<queue>

using namespace std;

char arr[31][31][31];
int visited[31][31][31];
int L,R,C;
struct Node{
    int l;
    int r;
    int c;
    int time;
};

Node startpoint,endpoint;
int arrived = 0;

int dz[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dx[]={1,-1,0,0,0,0};

void init(int L,int R, int C){
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            for(int k=0;k<30;k++){
                visited[i][j][k]=0;
            }
        }
    }
    arrived = 0;
    
    for(int i=0;i<L;i++){
        for(int j=0;j<R;j++){
            for(int k=0;k<C;k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k]=='S')startpoint = {i,j,k,0};
                if(arr[i][j][k]=='E')endpoint = {i,j,k,0};
            }
        }
    }
}

int bfs(Node startpoint){
    queue<Node>q;
    q.push(startpoint);
    visited[startpoint.l][startpoint.r][startpoint.c]=1;
    while(!q.empty()){
        Node now = q.front();q.pop();
        if(now.l==endpoint.l && now.r==endpoint.r && now.c==endpoint.c){
            return now.time;
        }
        for(int i=0;i<6;i++){
            int nl = now.l + dz[i];
            int nr = now.r + dy[i];
            int nc = now.c + dx[i];
            if(nl <0 || nl >= L || nr <0 || nr>=R || nc<0 || nc>=C)continue;
            if(arr[nl][nr][nc]=='#')continue;
            if(visited[nl][nr][nc]==1)continue;
            visited[nl][nr][nc]=1;
            q.push({nl,nr,nc,now.time+1});
            
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(1){
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0)break;
        
        init(L,R,C);
        int answer = bfs(startpoint);
        if(answer==-1)cout << "Trapped!\n";
        else cout << "Escaped in " << answer << " minute(s).\n";
        
    }
}
