#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    list<char> li;
    for(char i : s){
        li.push_back(i);
    }
    auto t = li.end();

    int n;
    cin >> n;
    
    char command;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command=='L'){
            if(t==li.begin())continue;
            t--;
        }
        else if(command=='D'){
            if(t==li.end())continue;
            t++;
        }
        else if(command=='B'){
            if(t==li.begin())continue;
            t--;
            t= li.erase(t);
        }
        else if(command=='P'){
            char c;
            cin >> c;
            li.insert(t,c);
        }

    }
    
    for(auto i : li){
        cout << i ;
    }
}
