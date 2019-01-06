import java.lang.*;

class Solution {
    public int rob(int[] nums) {
    int size=nums.length;
    if(size==0){
        return 0;
    }else if(size==1){
        return nums[0];
    }
    int[] num=new int[size+4];
    for(int i=0;i<size+4;i++){
        if(i<size){num[i]=nums[i];}
        else{num[i]=0;}
    }
    int i=0;
    while(i<size){
        if(num[i]>=num[i+1]){
            num[i+2]+=num[i];
            num[i+3]+=num[i];
            i+=2;
        }else if(num[i+1]<num[i]+num[i+2]){
            num[i+2]+=num[i];
            num[i+3]+=num[i+1];
            i+=2;
        }else{
            num[i+3]+=num[i+1];
            num[i+4]+=num[i+1];
            i+=3;
        }
    }
    int j=0;
    for(j=size+3;j>0;j--){
        if(num[j]!=0){
            break;
        }
        //System.out.println(num[j]);
    }
    if(j==0){
        return 0;
    }
    return Math.max(num[j],num[j-1]);
    }
}

public class problem198{
     public static void main(String args[]){
         int[] test={2,4,8,9,9,3};
         Solution temp=new Solution();
         //temp.rob(test);
         System.out.println(temp.rob(test));
    }
}