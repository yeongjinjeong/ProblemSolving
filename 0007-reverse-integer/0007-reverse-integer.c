#include<limits.h>

int reverse(int x){
    long long answer = 0;
    int num = x;
    while(num!=0){
        if(answer*10 >= INT_MAX || answer*10 <= INT_MIN) return 0;
        answer *= 10;
        int rest = num%10;
        answer += rest;
        num = num/10;
    }
    return answer;
}