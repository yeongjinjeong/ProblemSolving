#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    int arr[1001][1001]={0};
    int N;

    cin >> N;
    for(int i=1;i<=N;i++){
        int y,x;
        int w,h;
        cin >> x >>y >>w>>h;
        for(int m=y;m<y+h;m++){
            for(int n = x; n < x+w;n++){
                arr[m][n] = i;
            }
        }
    }
    
    vector<int>cnt;
    cnt.resize(N+1,0);
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
//            cout << arr[i][j] ;
            if(arr[i][j]!=0){
                cnt[arr[i][j]]+=1;
            }
        }
//        cout << "\n";
    }
    for(int i=1;i<N+1;i++){
        cout << cnt[i]<<"\n";
    }
    
}
