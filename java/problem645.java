import java.lang.Math;
class Solution {
    public int[] findErrorNums(int[] nums) {
        int size=nums.length;
        int[] result=new int[2];
        for(int i:nums){
            int index=Math.abs(i)-1;
            if(nums[index]>0)nums[index]*=-1;
            else if(nums[index]<0)result[0]=index+1;
        }
        for(int i=0;i<size;i++){
            if(nums[i]>0){
                result[1]=i+1;
                break;
            }
        }  
        return result;     
    }
}