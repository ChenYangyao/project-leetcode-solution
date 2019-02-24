class Solution {
    /*
    less than 5----->0;
    [5,10)----->1;

    special:5^{x} log5(n)

    total num of factor_5
    */
    public int trailingZeroes(int n) {
        long temp=5;
        int result=n/5;
        while(temp<=n){
            temp*=5;
            result+=n/temp;
        }
        return result;
    }
}
public class problem172{
     public static void main(String args[]){
         Solution test=new Solution();
         
         System.out.println(test.trailingZeroes(200));
    }
}