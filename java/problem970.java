import java.util.*;

class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        List<Integer> result=new ArrayList<Integer>();
        if(x<y){
            int temp=x;
            x=y;y=temp;
        }
        if(x==1 && y==1){
            if(bound>0){
                result.add(1);
            }
            return result;
        }
        if(y==1){
            int temp=1;
            while(temp+1<=bound){
                result.add(temp+1);
                temp*=x;
            }
            return result;
        }
        int max_index=0;
        int temp=y;
        while(true){
            if(temp<=bound){max_index++;}
            else break;
            temp=temp*y;
        }
        for(int i=0;i<=max_index;i++){
            for(int j=0;i<=max_index;j++){
                int temp_a=power(x,i)+power(y,j);
                if(temp_a<=bound){
                    result.add(temp_a);
                }else break;
            }
        }
        HashSet<Integer> H=new HashSet<Integer>(result);
        result.clear();
        result.addAll(H);
        Collections.sort(result);
        return result;

    }
    public int power(int num,int index){
        int result=1;
        while(index>0){
            result*=num;index--;
        }
        return result;
    }
}