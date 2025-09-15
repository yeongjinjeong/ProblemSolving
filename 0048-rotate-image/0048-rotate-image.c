void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i=0;i<matrixSize/2;i++){
        for(int j=i;j<matrixSize-i-1;j++){
            int y= i, x = j;
            int pre = matrix[y][x];
            int next;
            for(int k=0;k<4;k++){
                next = matrix[x][matrixSize-1-y];
                matrix[x][matrixSize-1-y] = pre;
                pre = next;
                int ny = x;
                int nx = matrixSize-1-y;
                y = ny;
                x = nx; 
            }
        }
    }
}