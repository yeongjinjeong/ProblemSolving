#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>arr;

int main(){
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int k,n;
        cin >> k;
        cin >> n;
        arr.clear();
        arr.resize(k+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            arr[0][i]=i;
        }
        for(int i=1;i<=k;i++){
            arr[i][1]=1;
        }
        for(int i=1;i<=k;i++){
            for(int j=2;j<=n;j++){
                arr[i][j]= arr[i][j-1] + arr[i-1][j];
            }
        }
        cout << arr[k][n] << "\n";
        
    }
}
