#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,K;

struct Node{
    int ind;
    int time;
};

int main(){
    cin >> N >> K;
    int visited[100001]={0};
    queue<Node>q;
    q.push({N,0});
    visited[N]=1;
    while(!q.empty()){
        Node now = q.front(); q.pop();
        int nexttime=now.time+1;
        if(now.ind==K){
            cout << now.time;
            return 0;
        }
        if(now.ind>0){
            if(now.ind*2 <= 100000 && visited[now.ind*2]==0 ){
                q.push({now.ind*2,nexttime-1});
                visited[now.ind*2]=1;
            }
            if(visited[now.ind-1]==0){
                q.push({now.ind-1,nexttime});
                visited[now.ind-1]=1;
            }
        }
        if(now.ind+1 <= 100000 &&visited[now.ind+1]==0){
            q.push({now.ind+1,nexttime});
            visited[now.ind+1]=1;
        }
        
    }
}
