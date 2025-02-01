#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    getline(cin, input);
    
    int cnt = 0;
    for(char a : input){
        if(a==' ') cnt++;
    }
    if(input[0]==' ') cnt--;
    if(input[input.length()-1]==' ') cnt--;
    
    cout << cnt+1;
    
    
    
}
