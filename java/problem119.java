import java.util.ArrayList;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result=new ArrayList<Integer>();
        if(rowIndex==0){
            result.add(1);
            return result;
        }
        if(rowIndex==1){
            result.add(1);result.add(1);
            return result;
        }
        
        //System.out.println(rowIndex);
        for(int i=0;i<rowIndex/2+1;i++){
            //System.out.println(i);
            int fuckingNum=C_num(rowIndex,i);
            result.add(fuckingNum);
        }
        int beg;
        if(rowIndex%2==0){
            beg=rowIndex/2-1;
        }else{
            beg=rowIndex/2;
        }
        for(int i=rowIndex/2+1;i<=rowIndex;i++){
            result.add(result.get(beg));
            beg--;
        }
        return result;
    }
    public int C_num(int n,int i){
        if(n==i){
            return 1;
        }if(i==0){
            return 1;
        }
        int[] up_num=new int[i];
        int[] down_num=new int[i];
        for(int j=0;j<i;j++){
            up_num[j]=n-j;
            down_num[j]=j+1;
        }
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(up_num[j]%down_num[k]==0){
                    up_num[j]=up_num[j]/down_num[k];
                    down_num[k]=1;
                }
            }
        }
        long up_result=up_num[0];
        for(int j=1;j<i;j++){
            up_result=up_result*up_num[j];
        }
        long down_result=down_num[0];
        for(int j=1;j<i;j++){
            down_result=down_result*down_num[j];
        }
        return (int)(up_result/down_result);   
    }

}