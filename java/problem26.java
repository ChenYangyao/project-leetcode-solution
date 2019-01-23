class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int currentPointer=0;
        int sweepPointer;
        for(sweepPointer=0;sweepPointer<nums.length;sweepPointer++){
            if(nums[sweepPointer]!=nums[currentPointer]){
                nums[currentPointer+1]=nums[sweepPointer];
                currentPointer++;
            }
        }
        return currentPointer+1;
    }
}