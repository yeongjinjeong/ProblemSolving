#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {        
    long long answer = 0;    
    long long mini = *min_element(times.begin(), times.end());
    long long maxi = *max_element(times.begin(), times.end());
    long long left = 1;
    long long right = maxi * n;
    while(left <= right){
        long long mid = (left+right)/2;
        long long target = 0;
        for(int i=0;i<times.size();i++){
            target += (mid/times[i]);            
        }
        if(target<n) {
            left = mid +1;
        }
        else {
            right = mid -1;
            answer = mid;
        }
    }                        
    return answer;
}            