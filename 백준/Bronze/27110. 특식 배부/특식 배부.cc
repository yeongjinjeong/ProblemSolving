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
    
    int N;
    cin >> N;
    
    
    int Max=0;
    for(int i=0;i<3;i++){
        int num;
        cin >> num;
        if(num > N) Max+=N;
        else Max += num;
    }
    cout << Max;
}

