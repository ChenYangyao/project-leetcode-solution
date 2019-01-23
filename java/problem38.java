class Solution {
    public String countAndSay(int n) {
        String result=new String("1");
        String temp;
        for(int i=1;i<n;i++){
            temp="";
            int current=0;int sweep;
            for(sweep=0;sweep<result.length();sweep++){
                if(result.charAt(sweep)!=result.charAt(current)){
                    temp+=String.valueOf(sweep-current);
                    temp+=result.charAt(current);
                    current=sweep;
                }
            }
            temp+=String.valueOf(sweep-current);
            //System.out.println(temp);
            temp+=result.charAt(current);
            //System.out.println(temp);
            result=temp;
        }
        return result;
    }
}

public class problem38{
     public static void main(String args[]){
         Solution test=new Solution();
         System.out.println(test.countAndSay(5));
    }
}