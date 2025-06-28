#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int>weights;
    for(int i=0;i<n;i++){
        int w;
        cin >> w;
        weights.push_back(w);
    }
    
    sort(weights.begin(),weights.end());
    int maxweight = 0;
    
    for(int i=0;i<weights.size();i++){
        int k = n - i;
        int weight = weights[i] * k;
        if(weight > maxweight)maxweight = weight;
        
    }
    cout << maxweight;
}
