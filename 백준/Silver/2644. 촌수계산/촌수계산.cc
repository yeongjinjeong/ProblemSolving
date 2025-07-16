#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<int>arr[101];
int visited[101]={0};
int a,b;

void bfs(){
    queue<pair<int,int>>q;
    q.push({a,0});
    visited[a]=1;
    while(!q.empty()){
        auto [cnum,ccnt]= q.front(); q.pop();
        if(cnum==b){
            cout << ccnt;
            return;
        }
        for(int i=0;i<arr[cnum].size();i++){
            int nnum = arr[cnum][i];
            if(visited[nnum]==1)continue;
            visited[nnum]=1;
            q.push({nnum,ccnt+1});
            
        }
    }
    
    cout << -1;
    return;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> a >> b;
    cin >> m;
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    bfs();
}
