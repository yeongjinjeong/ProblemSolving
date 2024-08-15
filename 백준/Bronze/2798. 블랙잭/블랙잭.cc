#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    int N,M;
    cin >> N >> M;
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int maxnum=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                int sum = arr[i]+arr[j]+arr[k];
                if( sum<=M && sum > maxnum){
                    maxnum=sum;
                }
            }
        }
    }
    cout << maxnum;
}
