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
    
    
    int sum =0;
    for(int i=0;i<5;i++){
        int num;
        cin >> num;
        sum += num*num;
    }
    int res = sum%10;
    
    cout << res;
    
}

