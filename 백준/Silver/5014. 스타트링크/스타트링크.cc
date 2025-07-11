#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int f,s,g,u,d;

int main(){
    cin >> f >> s >> g >> u >> d;
    queue<pair<int,int>>q;
    int visited[1000001]={0};
    int answer = -1;
    q.push({s,0});
    visited[s]=1;
    while(!q.empty()){
        pair<int,int> now = q.front();q.pop();
        if(now.first==g){
            if(answer==-1)answer=now.second;
            else if(answer > now.second) answer = now.second;
            continue;
        }
        
        for(int next : {now.first+u,now.first-d}){
            if(next > f || next <1)continue;
            if(visited[next]==1)continue;
            q.push({next,now.second+1});
            visited[next]=1;
            
        }
    }
    if(answer==-1)cout << "use the stairs";
    else cout << answer;
}
