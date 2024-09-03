#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;
vector<vector<int>>arr;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N>>M;
    arr.push_back(vector<int>(N+1, 0));
    for (int i = 1; i <= N; i++) {
        arr.push_back(vector<int>(N+1, 0));
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += (arr[i][j - 1]+arr[i-1][j]-arr[i-1][j-1]);
        }
    }
    /*for (int i = 1; i <= N; i++) {
        
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] <<' ';
            
        }
        cout << "\n";
    }*/
    for (int i = 0; i < M; i++) {
        int sy, sx, ey, ex;
        
        cin >> sy >> sx >> ey >> ex;
        
        int res = arr[ey][ex]-arr[ey][sx-1]-arr[sy-1][ex]+arr[sy-1][sx-1];
        
        cout << res <<"\n";
    }
    


    
}
