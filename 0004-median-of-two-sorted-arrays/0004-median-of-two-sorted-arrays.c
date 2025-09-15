double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *new_arr = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

    //nums1 에  아무런 배열도 없는 경우
    if(nums1Size==0){
        int median_ind = nums2Size/2;
        double median;
        if(nums2Size%2==0){
            median = (nums2[median_ind] + nums2[median_ind-1])/2.0;
        }
        else{
            median = nums2[median_ind];
        }

        return median;
    }

    //nums2 에 아무런 배열도 없는 경우
    if(nums2Size==0){
        int median_ind = nums1Size/2;
        double median;
        if(nums1Size%2==0){
            median = (nums1[median_ind] + nums1[median_ind-1])/2.0;
        }
        else{
            median = nums1[median_ind];
        }

        return median;
    }
    //nums1,2 배열에 접근하는 인덱스
    int ind1=0,ind2=0;

    //nums1,2 배열의 인덱스가 마지막 요소까지 도달했는지 확인하는 플래그 
    int finish1 = 0, finish2 = 0;

    //median 인덱스의 위치
    int median_ind = (nums1Size + nums2Size)/2;

    //median 위치까지만 반복
    for(int i=0;i<nums1Size + nums2Size+1;i++){
        //nums1 과 num2의 값을 비교하며 merge 한다.
        if(finish1 == 0 && ( ind2 >= nums2Size || nums1[ind1] <= nums2[ind2] )){
            new_arr[i] = nums1[ind1];
            ind1++;
            if(ind1==nums1Size) finish1 =1;
        }
        else if(finish2 ==0 && ( ind1 >= nums1Size || nums1[ind1] > nums2[ind2])){
            new_arr[i] = nums2[ind2];
            ind2++;
            if(ind2==nums2Size) finish2 =1;
        }    
    }
    double median;
    if((nums1Size + nums2Size)%2==0){
        median = (new_arr[median_ind] + new_arr[median_ind-1])/2.0;
    }
    else{
        median = new_arr[median_ind];
    }

    return median;
}