#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >>N;
    deque<int>dq;
    
    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }
    while(dq.size()>2){
        dq.pop_front();
        int num = dq.front();
        dq.pop_front();
        dq.push_back(num);
        
    }
    if(dq.size()==2){
        dq.pop_front();
        
    }
    int res = dq.front();
    
    cout << res;
}
