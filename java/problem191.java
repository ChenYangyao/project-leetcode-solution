class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int solution = 0;
        while(n!=0){
            solution += n&1;
            n >>>= 1; 
            System.out.println(n);
        }
        return solution;
    }
}

public class problem191{
     public static void main(String args[]){
         Solution test=new Solution();
         test.hammingWeight(7);

    }
}