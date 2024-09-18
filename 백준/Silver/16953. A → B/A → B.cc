#include <iostream>
using namespace std;
int main(){
    int start,target;
    cin >> start >> target;
    int cnt =1;
    while(target>start){
        if(target%2==0) target/=2;
        else if(target%10==1){
            target= (target-1)/10;
        }
        else break;
        cnt++;
    }
    
    if(target!=start) cnt = -1;
    
    cout << cnt;
}
