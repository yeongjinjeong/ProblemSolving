bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for(int i=0;i<boardSize;i++){
        int arr[10]={0};
        for(int j=0;j<boardColSize[i];j++){
            if(board[i][j]=='.')continue;
            int num = (int)(board[i][j]-'0');
            if(arr[num]==0)arr[num]=1;
            else {
                    //printf("row case : %d %d - %d\n", i,j, num);
                    return false;
                }
        }
    }

    for(int i=0;i<boardColSize[0];i++){
        int arr[10]={0};
        for(int j=0;j<boardSize;j++){
            if(board[j][i]=='.')continue;
            int num = (int)(board[j][i]-'0');
            if(arr[num]==0)arr[num]=1;
            else {
                    //printf("col case : %d %d - %d\n", i,j, num);
                    return false;
                }
        }
    }
    // 3x3 칸 9개에 대하여 2차원 좌표값(index)을 부여한다.
    for(int k=0;k<9;k++){
        int arr[10]={0};
        int row = k/3;
        int col = k%3;
        //3x3 칸 안에서 스도쿠 값들을 비교 
        for(int i=row*3;i<row*3+3;i++){
            for(int j=col*3;j<col*3+3;j++){
                if(board[i][j]=='.')continue;
                int num = (int)(board[i][j]-'0');
                if(arr[num]==0)arr[num]=1;
                else {
                    //printf("3x3 case : %d %d %d - %d\n",k, i,j, num);
                    return false;
                }
            }
        }
    }

    return true;

}