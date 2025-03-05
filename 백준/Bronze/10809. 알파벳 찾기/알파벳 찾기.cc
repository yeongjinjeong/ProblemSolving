#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin >> str;
    
    for(char a = 'a';a<='z';a++){
        if(str.find(a)==string::npos) cout << -1 << ' ';
        else cout << str.find(a) << " ";
    }
}
