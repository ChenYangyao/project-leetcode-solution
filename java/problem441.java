class Solution {
    public int arrangeCoins(int n) {
        if(n==0)return 0;
        int end=n;int beg=0;int med;
        while(end > beg){
            med=(end+beg)/2;
            if((((double)med+1)*(double)med)>(2*(double)n)){
                end=med;
            }else if((((double)med+1)*(double)med)<(2*(double)n)){
                beg=med;
            }else{
                return med;
            }
            //System.out.println("beg:"+beg+"; end:"+end+"; med:"+med);
            if(end-beg<=100)break;
        }
        int i;
        for(i=beg;i<=end;i++){
            if(((double)i*((double)i+1))>=(2*(double)n))break;
        }
        return ((double)i*((double)i+1))==(2*(double)n)?i:i-1;
    }
}
public class problem441{
     public static void main(String args[]){
         Solution test=new Solution();
         System.out.println(test.arrangeCoins(1804289383));
        //int med=112768085;int n=1804289383;
        //System.out.println((((double)med+1)*(double)med)+";"+(2*(double)n));
    }
}