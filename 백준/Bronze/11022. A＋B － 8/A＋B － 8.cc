#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    for(int i=1;i<=T;i++){
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " <<a <<" + " << b <<" = "<< (a+b) << "\n";
    }
}
