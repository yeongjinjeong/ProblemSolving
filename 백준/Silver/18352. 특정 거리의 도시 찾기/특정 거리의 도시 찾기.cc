#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N,M,K,X;
struct Node{
    int dest;
    int cost;
    bool operator<(Node right)const{
        if(cost > right.cost)return true;
        if(cost < right.cost)return false;
        return false;
    }
};
vector<vector<Node>>arr;
vector<int>dist;

void dijkstra(int start){
    dist.resize(N+1,21e8);
    priority_queue<Node>pq;
    pq.push({start,0});
    while(!pq.empty()){
        Node now = pq.top(); pq.pop();
        
        if(dist[now.dest] <= now.cost) continue;
        dist[now.dest] = now.cost;
        
        for(int i=0;i<arr[now.dest].size();i++){
            Node next = arr[now.dest][i];
            int nextCost = now.cost + next.cost;
            
            if(dist[next.dest] <= nextCost)continue;
            pq.push({next.dest,nextCost});
        }
    }
}

int main(){
    cin >>N >> M >> K >> X;
    arr.resize(N+1);
    
    
    for(int i=0;i<M;i++){
        int st, en;
        cin >> st >> en;
        arr[st].push_back({en,1});
    }
  
    dijkstra(X);
    
    bool is_K = false;
    
    for(int i=1;i<=N;i++){
        if(dist[i]==K){
            is_K = true;
            cout << i << "\n";
        }
    }
    if(!is_K) cout << -1;
}
