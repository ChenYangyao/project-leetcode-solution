class Solution {
    public int dominantIndex(int[] nums) {
        int size=nums.length;
        if(size==0){
            return -1;
        }else if(size==1){
            return 0;
        }
        int no_1,no_2,max_index;
        if(nums[0]>=nums[1]){
            no_1=nums[0];no_2=nums[1];
            max_index=0;
        }else{
            no_1=nums[1];no_2=nums[0];
            max_index=1;
        }
        for(int i=2;i<size;i++){
            if(nums[i]>no_1){
                no_2=no_1;
                no_1=nums[i];
                max_index=i;
            }else if(nums[i]>no_2){
                no_2=nums[i];
            }
        }
        if(no_1>=2*no_2){
            return max_index;
        }else{
            return -1;
        }
    }
}