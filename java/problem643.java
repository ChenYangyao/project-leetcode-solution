class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int max=sum;
        for(int i=k;i<nums.length;i++){
            sum=sum+(nums[i]-nums[i-k]);
            if(sum>max){
                max=sum;
            }
        }
        return (double)max/(double)k;       
    }
}
public class problem643{
     public static void main(String args[]){
         Solution test=new Solution();
         int[] nums={0,4,0,3,2};
         System.out.println(test.findMaxAverage(nums, 1));
    }
}