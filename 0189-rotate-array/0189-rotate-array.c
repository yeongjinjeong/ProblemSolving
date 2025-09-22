void rotate(int* nums, int numsSize, int k) {
    
    int ind = 0;
    int next_val = nums[ind];

    int *visited= (int*)malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++) visited[i] = 0;


    for(int i=0;i<numsSize;i++){
        while(visited[ind]==1){
            ind++;
            next_val = nums[ind];
        }
        int now_val = next_val;
        int next_ind = (ind+k) % numsSize;
        next_val = nums[next_ind];
        nums[next_ind] = now_val;
        visited[ind]=1;
        ind = next_ind;
    }
}