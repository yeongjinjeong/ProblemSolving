#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin >> N >> M;
    vector<int>arr;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(),arr.end());
    int stind=0;
    int enind=1;
    int answer=2000000000;
    while(stind!=N-1){
        if(stind==enind){
            enind++;
            continue;
        }
        int diff = arr[enind] - arr[stind];
        if(diff < M && enind < N-1) enind++;
        else if(diff < M && enind == N-1)break;
        else if(diff > M){
            if(answer > diff)answer = diff;
            stind++;
        }
        else{
            answer=M;
            break;
        }
    }
    cout << answer;
}
