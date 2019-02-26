import java.util.LinkedList;
import java.util.List;
class Solution {
    public int compress(char[] chars) {
        if(chars.length<=1)return chars.length;
        char tag=chars[0];
        int result=0;
        int count=1;
        int begin=0;
        for(int i=1;i<=chars.length;i++){
            char flag;
            /* be careful*/
            /*in order to deal with the last duplicated sub string*/
            if(i<chars.length){
                flag=chars[i];
            }else{
                flag=(char)(((int)chars[chars.length-1]-(int)'a'+1)%26);
            }

            if(flag==tag){
                count++;
            }else{
                List<Integer> temp=num_digit(count);
                chars[begin]=tag;
                if(temp.size()!=1){
                    for(int j=0;j<temp.size()-1;j++){
                        chars[begin+1+j]=(char)(temp.get(temp.size()-j-2).intValue()+48);
                    }
                }
                result+=1+temp.get(temp.size()-1);
                begin=result;
                tag=flag;count=1;
            }
        }
        return result;

    }
    public List<Integer> num_digit(int count){
        List<Integer> result=new LinkedList<Integer>();
        if(count==1){
            result.add(0);    
            return result;
        }
        int num=0;
        while(count>0){
            result.add(count%10);
            count=count/10;
            num++;
        }
        result.add(num);
        /*
        for(int item:result){
            System.out.println(item);
        }*/

        return result;
    }
}
public class problem443{
    public static void main(String args[]){
            //Solution test=new Solution();
            //test.num_digit(1); 
            int t=1;
            System.out.println((char)(t+48));    
    }
}