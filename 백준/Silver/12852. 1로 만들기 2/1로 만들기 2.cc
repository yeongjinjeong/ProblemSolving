#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    int N;
    cin >> N;

    vector<int> dp(N+1);
    vector<int> path(N+1); // 경로를 저장하는 배열
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + 1; // 1을 빼는 경우
        path[i] = i - 1;

        if (i % 2 == 0 && dp[i/2] + 1 < dp[i]) {
            dp[i] = dp[i/2] + 1; // 2로 나누는 경우
            path[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i/3] + 1 < dp[i]) {
            dp[i] = dp[i/3] + 1; // 3으로 나누는 경우
            path[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[N] << "\n";

    // 경로 출력
    int current = N;
    while (current > 0) {
        cout << current << " ";
        current = path[current];
    }
    cout << "\n";

    return 0;
}
