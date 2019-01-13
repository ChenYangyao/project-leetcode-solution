class Solution {
    public int pivotIndex(int[] nums) {
        int size=nums.length;
        if(size==1){
            return 0;
        }
        for(int i=size-2;i>=0;i--){
            nums[i]+=nums[i+1];
        }
        for(int i=0;i<size;i++){
            if(i!=0&&i!=size-1){
                if(nums[0]-nums[i+1]==nums[i]){
                    return i;
                }
            }else{
                if(i==0&&nums[1]==0){
                    return 0;
                }else if(i==size-1&&nums[0]-nums[i]==0){
                    return i;
                }
            }
        }
        return -1;
    }
}