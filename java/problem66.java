class Solution {
    public int[] plusOne(int[] digits) {
        int size=digits.length;
        for(int i=size-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]++;
                break;   
            }else{
                digits[i]=0;
            }    
        }
        if(digits[0]==0){
            int[] result=new int[size+1];
            result[0]=1;
            for(int i=1;i<result.length;i++){
                result[i]=0;
            }
            return result;
        }else{
            return digits;
        }
    }
}