class Solution {
    public boolean isPowerOfFour(int num) {
        if(num==1)return true;
        while(num>=5){
            if(num%4!=0){
                return false;
            }
            num=num/4;
        }
        return num==4;    
    }
}