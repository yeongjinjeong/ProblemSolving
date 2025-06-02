#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int arr[10]={0};

int main(){
    string num;
    cin >> num;
    for(int i=0;i<num.length();i++){
        arr[num[i]-'0']+=1;
    }
    
    int min = (int)ceil((arr[6] + arr[9])/2.0);
    
    for(int i=0;i<10;i++){
        if(i==6 || i==9)continue;
        if(arr[i]>min)min = arr[i];
    }
    
    cout << min;
}
