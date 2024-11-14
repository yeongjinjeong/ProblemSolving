#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    s = " " + s;
    int fir = 0;
    int sec = 0;
    vector<int> v;
    while(1){
        fir = s.find(" ", sec);
        if(fir == -1) break;
        sec = s.find(" ", fir+1);
        string temp = s.substr(fir + 1, sec - fir - 1);        
        int temp2 = stoi(temp);
        v.push_back(temp2);
    }
    sort(v.begin(), v.end());
    string tem1 = to_string(v[0]);
    string tem2 = to_string(v[v.size() - 1]);
    string answer = tem1 + " " + tem2;
    return answer;
}