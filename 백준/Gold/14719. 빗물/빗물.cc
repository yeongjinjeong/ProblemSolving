#include<iostream>
#include<vector>
using namespace std;
int h,w;
int arr[500][500]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> h >> w;
    for(int i=0;i<w;i++){
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            arr[h-j-1][i]=1;
        }
    }
    
    int block_start = 0;
    int start_ind;
    int answer=0;
    
    for(int i=h-1;i>=0;i--){
        for(int j=0;j<w;j++){
            if(arr[i][j]==0)continue;
            if(arr[i][j]==1 && block_start==0){
                block_start=1;
                start_ind = j;
            }
            else if(arr[i][j]==1 && block_start==1){
                answer += j - start_ind -1;
                start_ind = j;
            }
        }
        block_start = 0;
    }
    cout << answer;
}
