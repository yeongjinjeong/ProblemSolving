#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(string left,string right){
    if(left.length()< right.length()) return true;
    if(left.length()> right.length()) return false;
    
    if(left < right) return true;
    if(left > right) return false;
    
    return false;
    
}

int main(){
    int N;
    cin >> N;
    vector<string>arr(N);
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),cmp);
    
    for(int i=0;i<N;i++){
        if(i!=0 && arr[i]==arr[i-1])continue;
        cout << arr[i] << "\n";
    }
    
}
