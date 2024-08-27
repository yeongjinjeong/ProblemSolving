#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;
int check(string str){
    vector<char>left;
    if(str[0]==')') return 0;
    if(str[str.length()]=='(') return 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') left.push_back(str[i]);
        else if(str[i]==')' && left.size()==0) return 0;
        else if(str[i]==')') left.pop_back();
    }
    if(left.size()!=0)return 0;
    return 1;
}

int main() {
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        if(check(str))cout << "YES"<<"\n";
        else cout << "NO" << "\n";
    }
}
