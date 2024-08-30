#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >>T;
    for(int tc=0;tc<T;tc++){
        string func;
        int cnt;
        string arr_s;
        cin >> func;
        cin >> cnt;
        cin >> arr_s;
        deque<int>arr;
        if(cnt==0 && func.find('D')!= string::npos){
            cout << "error" <<"\n";
            continue;
        }
        else if(cnt==0 && func.length() != 0){
            cout << "[]" <<"\n";
            continue;
        }
        arr_s = arr_s.substr(1,arr_s.length()-2);
        arr_s += ',';
        string num="";
        for(int i=0;i<arr_s.length();i++){
            if(arr_s[i]==','){
                arr.push_back(stoi(num));
                num ="";
                continue;
            }
            num += arr_s[i];
            
        }
        
        int flag = 1;
        int Rcnt=0;
        for(int i=0;i<func.length();i++){
            if(arr.size()==0){
                flag = 0;
                break;
            }
            if(func[i]=='D' && Rcnt%2==0) {arr.pop_front();}
            else if(func[i]=='D' && Rcnt%2==1) {arr.pop_back();}
            else if(func[i]=='R'){
                Rcnt++;
                continue;
            }
        }
        if(Rcnt%2==1){
            deque<int>tmp;
                                
            for(int j=0;j<arr.size();j++){
                int num = arr[j];
                tmp.push_front(num);
                
            }
            for(int j=0;j<tmp.size();j++){
                arr.pop_front();
                arr.push_back(tmp[j]);
            }
        }
        if(flag==0){
            cout << "error" << "\n";
        }
        else{
            
            vector<string>ans;
            ans.push_back("[");
            if(arr.size()!=0){
                for(int i=0;i<arr.size();i++){
                    ans.push_back(to_string(arr[i]));
                    ans.push_back(",");
                }
                ans.pop_back();
            }
            
            ans.push_back("]");
            for(int i=0;i<ans.size();i++){
                cout << ans[i];
            }
            cout << "\n";
        }
        
        
    }
}
