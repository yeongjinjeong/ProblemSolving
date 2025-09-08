double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *new_arr = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

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

    int ind1=0,ind2=0;
    int finish1 = 0;
    int finish2 = 0;

    int median_ind = (nums1Size + nums2Size)/2;

    for(int i=0;i<median_ind+1;i++){
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