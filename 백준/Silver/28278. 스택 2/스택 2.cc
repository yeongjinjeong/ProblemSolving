#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int>sta;
    cin >> N;
    for(int i=0;i<N;i++){
        int command;
        cin >> command;
        if(command ==1){
            int x;
            cin >> x;
            sta.push_back(x);
        }
        else if(command==2){
            if(sta.size()==0){
                cout << -1 << "\n";
                continue;
            }
            //cout << *(sta.end()-1) << "\n";
            cout << sta.back() << "\n";
            sta.pop_back();
        }
        else if(command==3){
            cout << sta.size() << "\n";
        }
        else if(command==4){
            if(sta.size()==0){
                cout << 1 << "\n";
            }
            else cout << 0 << "\n";
        }
        else if(command==5){
            if(sta.size()==0){
                cout << -1 << "\n";
                continue;
            }
            //cout << *(sta.end()-1) << "\n";
            cout << sta.back() << "\n";

        }
        
    }
    return 0;
}

