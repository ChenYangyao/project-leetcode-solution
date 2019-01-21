class Solution {
    public boolean isPerfectSquare(int num) {
        int beg=0;int end=65536;//2**16
        int med;
        while(true){
            if(end-beg<=1){
                break;
            }
            med=(beg+end)/2;
            int temp=med*med;
            if(temp>num||temp<0){
                end=med;
            }else if(temp<num){
                beg=med;
            }else{
                return true;
            }
            
        }
        return beg*beg==num||end*end==num;
    }
}
public class problem367{
     public static void main(String args[]){
         Solution test=new Solution();
         System.out.println(test.isPerfectSquare(2147395600));
    }
}