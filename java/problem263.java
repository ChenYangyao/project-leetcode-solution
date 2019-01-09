/*import java.util.*;
class Solution {
    public boolean isUgly(int num) {
        if(num<=0){
            return false;
        }
        int beg=0,end=nums.length;
        while(beg+1<end){
            int med=(beg+end)/2;
            if(nums[med]==num){
                return true;
            }else if(nums[med]>num){
                end=med;
            }else if(nums[med]<num){
                beg=med;
            }
        }
        return false;
     
    }
    private static int[] nums=new int[7657];
    Solution(){
        int factor_2=30,factor_3=18,factor_5=12;
        int index=0;
        for(int i=0;i<=factor_5;i++){
            for(int j=0;j<=factor_3;j++){
                for(int k=0;k<=factor_2;k++){
                    nums[index]=pow(2,k)*pow(3,j)*pow(5,i);
                    //System.out.println(nums[index]);
                    index++;
                   
                }
            }
        }
        Arrays.sort(nums);
        //for(int i=0;i<nums.length;i++){
        //    System.out.println(nums[i]);
        //}
    }
    public static int pow(int x,int power){
        if(power==0){
            return 1;
        }
        int result=x;
        for(int i=1;i<power;i++){
            result=result*x;
        }
        return result;
    }
    
}*/
class Solution {
    public boolean isUgly(int num) {
        for (int i=2; i<6 && num>0; i++){
            while (num % i == 0) num /= i;
        }
        return num == 1;
    }
}


public class problem263{
    public static void main(String args[]){
        Solution test=new Solution();
        System.out.println(test.isUgly(2));
    }
}