int lengthOfLongestSubstring(char* s) {
    int dat[256] = {0}; 
    int startind = 0, endind = 0;
    int answer = 0;

    while (s[endind]!=0) {
        char end_char = s[endind];

        // 중복 문자일 경우, 시작 포인터 이동
        while (dat[end_char]==1) {
            dat[s[startind]]--;
            startind++;
        }

        // 문자 사용 표시
        dat[end_char] = 1;  
        int len = endind - startind + 1;
        if (len > answer) answer = len;

        endind++;
    }

    return answer;
}