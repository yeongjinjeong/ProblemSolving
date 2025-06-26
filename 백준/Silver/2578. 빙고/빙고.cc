#include<iostream>
#include<vector>

using namespace std;

int visited[5][5]={0};
int num[26];
int cnt=0;
pair<int,int>dat[26];

void check(int number){
    pair<int,int>now = dat[number];
    visited[now.first][now.second] = 1;
    int row = 0;
    int column =0;
    int rcross =0;
    int lcross =0;
    
    for(int i=0;i<5;i++){
        if(visited[now.first][i]==1)row++;
    }
    if(row==5)cnt++;
    
    for(int i=0;i<5;i++){
        if(visited[i][now.second]==1)column++;
    }
    if(column==5)cnt++;
    
    if(now.first==now.second){
        for(int i=0;i<5;i++){
            if(visited[i][i]==1)rcross++;
        }
        if(rcross==5)cnt++;
    }
    if(now.first==4-now.second){
        for(int i=0;i<5;i++){
            if(visited[i][4-i]==1)lcross++;
        }
        if(lcross==5)cnt++;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int n;
            cin >> n;
            dat[n]={i,j};
        }
    }
    for(int i=1;i<26;i++){
        cin >> num[i];
    }
    for(int i=1;i<26;i++){
        check(num[i]);
        if(cnt>=3){
            cout << i;
            break;
        }
        
    }
    return 0;
}
