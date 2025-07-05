#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<double>ys;
    vector<double>xs;
    
    for(int i=0;i<n;i++){
        int y, x;
        cin >> x >> y;
        ys.push_back(y);
        xs.push_back(x);
    }
    double sum1=0;
    double sum2=0;
    for(int i=0;i<n-1;i++){
        sum1 += (xs[i]*ys[i+1]);
    }
    sum1 += xs[n-1]*ys[0];
    
    
    
    
    for(int i=1;i<n;i++){
        sum2 += (xs[i]*ys[i-1]);
    }
    sum2 += xs[0]*ys[n-1];
    
    
    
    double answer = abs(sum1 - sum2)/2;
    
    
    cout << fixed;
    cout.precision(1);
    cout << answer;
    
    
}
