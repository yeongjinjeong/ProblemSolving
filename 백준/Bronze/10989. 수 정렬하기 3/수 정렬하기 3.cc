#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10001]={0};

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        arr[num]+=1;
    }
    for(int i=0;i<10001;i++){
        if(arr[i]==0)continue;
        for(int j=0;j<arr[i];j++){
            cout << i << "\n";
        }
    }
    
    
}
