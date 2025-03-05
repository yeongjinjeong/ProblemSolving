#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge{
    int dest;
    int cost;
    bool operator<(Edge right) const{
        if(cost < right.cost) return false;
        if(cost > right.cost) return true;
        return false;
    }
};

vector<vector<Edge>>arr;
vector<int> dist;
int N,E;

int dijkstra(int st, int en){
    dist.clear();
    dist.resize(N+1,21e8);
    priority_queue<Edge>pq;
    pq.push({st,0});
    
    while(!pq.empty()){
        Edge now = pq.top(); pq.pop();
        
        if(dist[now.dest] <= now.cost) continue;
        dist[now.dest] = now.cost;
        
        for(int i=0;i<arr[now.dest].size();i++){
            Edge next = arr[now.dest][i];
            int nextCost = now.cost + next.cost;
            if(dist[next.dest] <= nextCost) continue;
            pq.push({next.dest,nextCost});
            
        }
    }
    if(dist[en]==21e8) return -1;
    return dist[en];
}

int main(){
    cin >> N >> E;
    arr.resize(N+1);
    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    int v1,v2;
    cin >> v1 >> v2;
    
    int ans = -1;
    int check1=1, check2=1;
    if(dijkstra(1,v1)==-1 || dijkstra(v1,v2) ==-1 || dijkstra(v2,N)==-1){
        check1 = -1;
    }
    if(dijkstra(1,v2) == -1 || dijkstra(v2,v1)== -1 || dijkstra(v1,N)==-1){
        check2 = -1;
    }
    
    if(check1 == 1 && check2 ==1){
        ans = min((dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,N)),(dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,N)));
    }
    else if(check1 ==1 && check2 == -1){
        ans = dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,N);
    }
    else if(check1 == -1 && check2 ==1){
        ans = dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,N);
    }
    cout << ans;
}


