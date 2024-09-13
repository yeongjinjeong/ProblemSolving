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
    string arr;
    cin >> arr;
    
    int sum =0;
    for(int i=0;i<N;i++){
        sum += (int)(arr[i]-'0');
    }
    
    cout << sum;
}

