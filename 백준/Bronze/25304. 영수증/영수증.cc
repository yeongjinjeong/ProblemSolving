#include<iostream>

using namespace std;

int main(){
    int total;
    int sum=0;
    int type;
    cin >> total;
    cin >> type;
    
    for(int i=0;i<type;i++){
        int price;
        int cnt;
 
        cin >> price >> cnt;
        sum+= price * cnt;
        
    }
    
    if(sum==total) cout << "Yes";
    else cout << "No";
    
    return 0;
}
