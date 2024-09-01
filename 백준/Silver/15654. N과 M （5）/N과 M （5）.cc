#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int N,M;

vector<int>arr;
vector<int>path;
vector<int>visited;
void dfs(int start_ind, int level){
    if(level >=M){
        for(int i=0;i<path.size();i++){
            cout << path[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<N;i++){
        if(visited[i]==1)continue;
        path.push_back(arr[i]);
        visited[i]=1;
        dfs(i,level+1);
        path.pop_back();
        visited[i]=0;
    }
    
}

int main(){
    cin >> N >> M;
    visited.resize(N,0);
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    dfs(0,0);
}
