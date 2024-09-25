void moveZeroes(int* nums, int numsSize) {
    int x=0;
    
    for(int i=0; i< numsSize; i++){
        if(nums[i]!=0){
            nums[x] = nums[i];
            x++;
        }
    }
    while(x<numsSize){
        nums[x] = 0;
        x++;
    }
    
}
