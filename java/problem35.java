class Solution {
    public int searchInsert(int[] nums, int target) {
        int size=nums.length;
        int beg=0,end=size-1;
        int med;
        
        while(beg<=end){
            med=(beg+end)/2;
            if(nums[med]==target){
                return med;
            }else if(nums[med]>target){
                end=med;
            }else if(nums[med]<target){
                beg=med;
            }
            if(end-beg<=1){
                if(nums[beg]>=target){
                    return beg;
                }else if(nums[end]>=target){
                    return end;
                }else if(nums[end]<target){
                    return end+1;
                }
            }
        }
        return -1;
        
    }
}