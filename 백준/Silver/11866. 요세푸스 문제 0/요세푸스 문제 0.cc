#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,K;
    
    cin >> N >> K;
    queue<int>q;
    
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    cout << "<";
    for(int i=1;i<=N;i++){
        for(int j=0;j<K-1;j++){
            int next = q.front();
            q.pop();
            q.push(next);
        }
        int num = q.front();q.pop();
        cout << num;
        if(i==N)cout << ">";
        else cout << ", ";
    }
    

}
