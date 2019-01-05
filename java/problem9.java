import java.util.*;

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }else if(x<10){
            return true;
        }
        List<Integer> temp=numToArray(x);
        for(int i=0,j=temp.size()-1;j>i;i++,j--){
            if(temp.get(i)!=temp.get(j)){
                return false;
            }
        }
        return true;
    }
    public List<Integer> numToArray(int x){
        List<Integer> result=new ArrayList<>();
        while(x>0){
            result.add(x%10);
            //System.out.println(x%10);
            x=x/10;
        }
        return result;
    }
}

public class problem9{
     public static void main(String args[]){
         Solution test=new Solution();
         System.out.println(test.isPalindrome(121));
    }
}