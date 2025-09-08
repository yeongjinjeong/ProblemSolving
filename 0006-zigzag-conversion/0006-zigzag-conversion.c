#include<string.h>

char* convert(char* s, int numRows) {
    int char_cnt = strlen(s);
    char *answer = malloc((char_cnt+1) * sizeof(char));

    //v자 형태의 zigzag 가 몇 번 반복되는 지 구한다.
    int zig_cnt;
    if(numRows==1){
        zig_cnt = char_cnt;
        return s;
    }
    else{
        if(char_cnt % (numRows + (numRows -2))==0){
            zig_cnt = char_cnt / (numRows + (numRows -2));
        } 
        else{
            zig_cnt = char_cnt / (numRows + (numRows -2)) + 1;
        }
        int ans_ind = 0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<zig_cnt;j++){

                int target_ind = j*(numRows + (numRows -2)) + i;
                if(target_ind >= char_cnt)continue;
                answer[ans_ind] = s[target_ind];
                ans_ind++;
                
                //첫 번째와 마지막 열은 zigzag 카운트 당 최대 1번이다.
                if(i==0 || i==numRows-1)continue;
                
                target_ind = (j+1)*(numRows + (numRows -2)) - i;
                if(target_ind >= char_cnt)continue;
                answer[ans_ind] = s[target_ind];
                ans_ind++;
            }
        }
        answer[ans_ind] = '\0';
    }

    
    return answer;

}