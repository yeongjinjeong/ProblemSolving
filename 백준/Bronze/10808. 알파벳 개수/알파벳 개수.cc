#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[27]={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']+=1;
    }
    for(int i=0;i<26;i++){
        cout << arr[i] << ' ';
    }
    
}
