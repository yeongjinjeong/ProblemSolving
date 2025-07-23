#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<int>arr[501];

int visited[501]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    queue<int>q;
    visited[1]=1;
    int answer = 0;
    for(int i=0;i<arr[1].size();i++){
        int fr = arr[1][i];
        q.push(fr);
        visited[fr]=1;
        answer++;
    }
    
    while(!q.empty()){
        int fr = q.front();q.pop();
        for(int i=0;i<arr[fr].size();i++){
            int frfr = arr[fr][i];
            if(visited[frfr]==1)continue;
            visited[frfr]=1;
            answer++;
        }
    }
    
    cout << answer;
}
