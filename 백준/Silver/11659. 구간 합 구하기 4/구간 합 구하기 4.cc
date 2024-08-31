#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,M;
    cin >> N>>M;
    vector<int>sum(N+1);
    sum[0]=0;
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        sum[i] = sum[i-1]+num;
    }
    for(int i=0;i<M;i++){
        int st,en;
        cin >>st>>en;
        int res=sum[en]-sum[st-1];
        cout << res << "\n";
    }
}
