#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
   
    int arr[9]={0};
    int visited[9]={0};
    for(int i=0;i<9;i++){
        cin >> arr[i];
    }
    sort(arr,arr+9);
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            int sum=0;
            visited[i]=1;
            visited[j]=1;
            for(int k=0;k<9;k++){
                if(visited[k]==0){
                    sum+= arr[k];
                }
            }
            if(sum==100){
                for(int k=0;k<9;k++){
                    if(visited[k]==0){
                        cout << arr[k] << "\n";
                    }
                }
                return 0;
            }
            visited[i]=0;
            visited[j]=0;
        }
    }
    
}
