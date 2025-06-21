#include<iostream>
#include<string>
#include<vector>

using namespace std;

char arr[51][51];
int N,M;
int mincnt;

void check(int n,int m){
    //B start
    char nextch = 'B';
    int cnt = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[n+i][m+j]!=nextch)cnt++;
            if(nextch=='B') nextch='W';
            else if(nextch=='W') nextch='B';
        }
        if(nextch=='B') nextch='W';
        else if(nextch=='W') nextch='B';
    }
    if(cnt < mincnt)mincnt=cnt;
    
    nextch = 'W';
    cnt =0;
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[n+i][m+j]!=nextch)cnt++;
            if(nextch=='B') nextch='W';
            else if(nextch=='W') nextch='B';
        }
        if(nextch=='B') nextch='W';
        else if(nextch=='W') nextch='B';
    }
    if(cnt < mincnt)mincnt=cnt;
}


int main(){
    cin >> N >> M;
    mincnt = N*M;
    
    for(int i=0;i<N;i++){
        string r;
        cin >> r;
        for(int j=0;j<M;j++){
            arr[i][j]=r[j];
        }
    }
    for(int i=0;i<N+1-8;i++){
        for(int j=0;j<M+1-8;j++){
            check(i,j);
        }
    }
    
    cout << mincnt;
    
    return 0;
    
}
