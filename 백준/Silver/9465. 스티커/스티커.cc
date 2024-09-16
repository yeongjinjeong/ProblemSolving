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
    
    int T;
    cin >> T;
    
    
    for(int tc=0;tc<T;tc++){
        int N;
        cin >> N;
        vector<vector<int>>arr;
        vector<vector<int>>dp;
        arr.resize(2,vector<int>(N+1));
        dp.resize(2,vector<int>(N+1,0));
        for(int i=1;i<=N;i++){
            cin >> arr[0][i];
        }
        for(int i=1;i<=N;i++){
            cin >> arr[1][i];
        }
        dp[0][1]=arr[0][1];
        dp[1][1]=arr[1][1];
        for(int i=2;i<=N;i++){
            dp[0][i]=max(dp[1][i-1],dp[1][i-2])+arr[0][i];
            dp[1][i]=max(dp[0][i-2],dp[0][i-1])+arr[1][i];
        }
        
        int res = max(dp[0][N],dp[1][N]);
        
        cout << res << "\n";

    }
}

/*
2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80
*/
