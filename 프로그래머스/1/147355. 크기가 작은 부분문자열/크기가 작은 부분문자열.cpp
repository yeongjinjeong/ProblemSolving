#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int len = p.length();
    int answer = 0;
    for(int i=0;i<=t.length()-len;i++){
        if(stoll(t.substr(i,len))<= stoll(p)) answer++;
    }
    
    return answer;
}