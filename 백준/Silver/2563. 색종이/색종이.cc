#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    int arr[101][101]={0};
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int y,x;
        cin >> y >>x;
        for(int m=y;m<y+10;m++){
            for(int n = x; n < x+10;n++){
                arr[m][n] += 1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(arr[i][j]!=0)cnt++;
        }
    }
    cout << cnt;
}
