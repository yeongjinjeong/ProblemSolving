#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    int dat[1000001]={0};
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dat[arr[i]]+=1;
    }
    
    int x;
    cin >> x;
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(x<=arr[i])continue;
        int target = x - arr[i];
        if(target > 1000000)continue;
        if(dat[target]==1) cnt++;
    }
    int result = cnt/2;
    cout << result;
    
    return 0;
    
    
}
