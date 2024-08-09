#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;



int main(){
    
    vector<int>triangle(3);
    cin >> triangle[0]>>triangle[1]>>triangle[2];
    if(triangle[0]==0 && triangle[1]==0 && triangle[2]==0) return 0;
    while(1){
        
        sort(triangle.begin(),triangle.end());
        int first = triangle[2] * triangle[2];
        int second = triangle[1] * triangle[1];
        int third = triangle[0] * triangle[0];
        if(third + second == first){
            cout << "right" << "\n";
        }
        else{
            cout << "wrong" << "\n";

        }
        cin >> triangle[0]>>triangle[1]>>triangle[2];
        if(triangle[0]==0 && triangle[1]==0 && triangle[2]==0) return 0;
        
    }
    return 0;

}
