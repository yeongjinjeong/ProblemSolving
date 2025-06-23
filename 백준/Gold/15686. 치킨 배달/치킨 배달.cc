#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int N,M;
int arr[51][51];
struct Node{
    int y;
    int x;
    int cost=2500;
};

vector<Node>home;
vector<pair<int,int>>chicken;
int visited[14]={0};
int answer;
vector<vector<int>>costs;

void dfs(int idx, int depth){
    if(depth >= M){
        int total=0;
        for(int i=0;i<home.size();i++){
            int minval=2500;
            for(int j=0;j<chicken.size();j++){
                if(visited[j]==0)continue;
                if(minval > costs[i][j])minval = costs[i][j];
            }
            total += minval;
            if(total > answer) return;
        }
        if(answer>total)answer = total;
        return;
    }
    for(int i=idx;i<chicken.size();i++){
        if(visited[i]==1) continue;
        visited[i]=1;
        
        dfs(i + 1,depth+1);
        
        visited[i]=0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)home.push_back({i,j});
            else if(arr[i][j]==2)chicken.push_back({i,j});
        }
    }
    answer = int(home.size()) * home[0].cost;
    
    costs.resize(home.size(),vector<int>(chicken.size()));
        
    for(int i=0;i<chicken.size();i++){
        int cy = chicken[i].first;
        int cx = chicken[i].second;
        
        for(int j=0;j<home.size();j++){
            int distance = abs(home[j].y - cy) + abs(home[j].x - cx);
            costs[j][i] = distance;
        }
    }
    
    dfs(0,0);
    
    cout << answer;
    
    return 0;
    
}
