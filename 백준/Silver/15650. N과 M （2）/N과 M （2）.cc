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
void dfs(int start_ind, int level){
    if(level >=M){
        for(int i=0;i<path.size();i++){
            cout << path[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i=start_ind+1;i<N;i++){
        path.push_back(arr[i]);
        dfs(i,level+1);
        path.pop_back();
    }
    
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        arr.push_back(i);
    }
    dfs(-1,0);
}
