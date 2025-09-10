#include<limits.h>

int reverse(int x){
    long long answer = 0;
    int num = x;
    while(num!=0){
        //int의 범위가 넘어가는 경우는 예외 처리
        if(answer*10 >= INT_MAX || answer*10 <= INT_MIN) return 0;
        
        //이전 값에 10을 곱해주며 다음 숫자를 더해준다.
        answer *= 10;
        int rest = num%10;
        answer += rest;
        num = num/10;
    }
    return answer;
}