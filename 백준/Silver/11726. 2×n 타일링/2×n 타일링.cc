#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long>dp(N+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<N+1;i++){
        dp[i]=dp[i-1]%10007+dp[i-2]%10007;
    }
    cout << dp[N]%10007;
}
