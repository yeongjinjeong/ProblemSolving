#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int index;
    int ladder_to=0;
    int snake_to=0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin >> N >> M;
    
    Node arr[101];
    for(int i=1;i<101;i++){
        arr[i].index = i;
    }
    
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        arr[x].ladder_to = y;
    }
    
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        arr[u].snake_to = v;
    }
    
    queue<pair<int,int>>q;
    int visited[101]={0};
    visited[1]=1;
    if(arr[1].ladder_to!=0)q.push({arr[1].ladder_to,0});
    else q.push({1,0});
    
    while(!q.empty()){
        pair<int,int> now = q.front();q.pop();
        if(now.first ==100){
            cout << now.second;
            return 0;
        }
        for(int i=1;i<=6;i++){
            int next = now.first + i;
            if(next > 100)continue;
            if(arr[next].snake_to!=0){
                next = arr[next].snake_to;
            }
            if(arr[next].ladder_to!=0){
                next = arr[next].ladder_to;
            }
            if(visited[next]==1)continue;
            visited[next]=1;
            q.push({next,now.second+1});
            
        }
        
        
    }
    
    
    return 0;
    
    
    
}
