import java.util.*;
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        paragraph=paragraph.toLowerCase()+".";
        //System.out.println(paragraph);
        Map<String, Integer> banned_test = new HashMap<String, Integer>();
        Map<String, Integer> result= new HashMap<String, Integer>();
        for(int i=0;i<banned.length;i++){
            //System.out.println(banned[i].toLowerCase());
            banned_test.put(banned[i].toLowerCase(),0);
        }
        int beg=0;int end=0;
        int size=paragraph.length();
        byte tag=0;
        for(int i=0;i<size;i++){
            if(!isSplit(paragraph.charAt(i))&&tag==0){
                beg=i;
                tag=1;
            }
            if(isSplit(paragraph.charAt(i))&&tag==1){
                end=i-1;
                tag=2;
            }
            if(tag==2){
                String temp=paragraph.substring(beg,end+1);
                //System.out.println(temp);
                if(!banned_test.containsKey(temp)){
                    if(result.containsKey(temp)){
                        result.put(temp,result.get(temp)+1);
                    }else{
                         result.put(temp,1);
                    }
                }
                tag=0;
             }
        }
        int max_index=0;
        String s="";
        for(String key:result.keySet()){
            if(result.get(key)>max_index){
                max_index=result.get(key);
                s=key;
            }
        }
        return s;

    }
    public boolean isSplit(char s){
        if(s>'z'||s<'a'){
            return true;
        }else{
            return false;
        }
    }
}

public class problem819{
     public static void main(String args[]){
         Solution test=new Solution();
         String paragraph="Bob hit a ball, the hit BALL flew far after it was hit.";
         String[] banned={"hit"};
         String temp=test.mostCommonWord(paragraph, banned);
        System.out.println(temp);
         //one bug lay in string spliting
    }
}