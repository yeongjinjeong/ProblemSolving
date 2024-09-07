#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    int N,S;
    cin >> N >> S;
    
    vector<int>arr(N,0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int minLen=N*2;
    int st=0,en=0;
    int Sum=arr[st];
    while(st!=N && en!=N){
        if(Sum >= S){
            int Len = en - st +1;
            if(minLen > Len){
                minLen = Len;
            }
            Sum -= arr[st];
            st++;
        }
        else{
            en++;
            Sum+=arr[en];
        }
    }
    if(minLen==N*2){
        minLen =0;
    }
    cout << minLen;
}
