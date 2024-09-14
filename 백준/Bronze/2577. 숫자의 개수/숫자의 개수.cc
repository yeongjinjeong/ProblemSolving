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
    
    int a,b,c;
    int cnt[10]={0};
    cin >> a;
    cin >> b;
    cin >> c;
    
    string sum = to_string(a*b*c);
    for(int i=0;i<sum.length();i++){
        int num = (sum[i]-'0');
        cnt[num]++;
    }
    for(int i=0;i<10;i++){
        cout << cnt[i] << "\n";
    }
    

}

