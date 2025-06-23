#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        int score=0;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='O'){
                cnt+=1;
                score += cnt;
            }
            else if(s[i]=='X')cnt=0;
        }
        cout << score <<"\n";
    }
}
