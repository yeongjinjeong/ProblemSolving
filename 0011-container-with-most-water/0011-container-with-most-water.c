int maxArea(int* height, int heightSize) {
    int start =0;
    int end = heightSize - 1 ;
    int answer = 0;
    
    while(start != end){
        //길이가 작은 것을 세로로
        int len = ((height[start] > height[end]) ? height[end] : height[start]);
        int width = end - start;
        int area = len * width;

        if(area > answer){
            answer = area;
        }
        
        (height[start] > height[end]) ? end-- : start++;

    }

    return answer;
    
}