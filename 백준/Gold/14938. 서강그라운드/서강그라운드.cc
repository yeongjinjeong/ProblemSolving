#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m,r;

struct Edge{
    int dest;
    int cost;
    bool operator<(Edge right)const{
        if(cost < right.cost) return false;
        if(cost > right.cost) return true;
        return false;
    }
};

vector<vector<Edge>>arr;
vector<int>item;
vector<int>dist;

void dijkstra(int st){
    dist.clear();
    dist.resize(n+1,21e8);
    priority_queue<Edge>pq;
    pq.push({st,0});
    
    while(!pq.empty()){
        Edge now = pq.top();pq.pop();
        
        if(dist[now.dest] <= now.cost) continue;
        
        dist[now.dest] = now.cost;
        
        for(int i=0;i<arr[now.dest].size();i++){
            Edge next = arr[now.dest][i];
            int nextCost = now.cost + next.cost;
            
            if(dist[next.dest] <= nextCost) continue;
            pq.push({next.dest,nextCost});
        }
    }
}

int main(){
    cin >> n >> m >> r;
    
    arr.resize(n+1);
    item.resize(n+1);
    
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        item[i]=t;
    }
    
    for(int i=0;i<r;i++){
        int a,b,l;
        cin >> a >> b >> l;
        arr[a].push_back({b,l});
        arr[b].push_back({a,l});
    }
    
    int max_total=0;
    
    for(int i=1;i<=n;i++){
        dijkstra(i);
        int total=0;
        for(int j=1;j<=n;j++){
            if(dist[j]<=m) total += item[j];
        }
        
        if(total > max_total) max_total = total;
    }
    
    cout << max_total;
}
