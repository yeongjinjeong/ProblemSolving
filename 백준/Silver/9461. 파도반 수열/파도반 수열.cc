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
        long long dp[101];
        dp[1]=1;dp[2]=1;dp[3]=1;
        for(int i=4;i<=N;i++){
            dp[i]=dp[i-2]+dp[i-3];
        }
        cout << dp[N]<<"\n";
    }
}
