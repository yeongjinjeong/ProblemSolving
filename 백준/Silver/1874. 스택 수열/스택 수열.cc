#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<int>stack;
vector<char>op;

int main(){
    int N;
    cin >> N;
    stack.resize(N+1);
    stack.push_back(0);
    int t=1;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        int last = stack[stack.size()-1];
        if(num > last){
            for(int j=t;j<=num;j++){
                stack.push_back(j);
                op.push_back('+');
                t++;
            }
            op.push_back('-');
            stack.pop_back();
        }
        else if(num == last){
            op.push_back('-');
            stack.pop_back();
        }
        else if(num < last){
            cout << "NO";
            return 0;
        }
        
    }
    for(int i=0;i<op.size();i++){
        cout << op[i] << "\n";
    }
}
