#include<iostream>

using namespace std;

int main(){
    int arr[101][101]={0};
    int N,M;
    cin >> N  >> M;
    
    for(int i=0;i<N;i++){
        int sy,sx,ey,ex;
        cin >> sy >> sx >> ey >> ex;
        for(int y=sy; y<=ey;y++){
            for(int x=sx; x<=ex;x++)
                arr[y][x]++;
        }
    }
    int answer=0;
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++){
            if(arr[i][j]<=M)continue;
            answer++;
        }
    }
    
    cout << answer;
}
