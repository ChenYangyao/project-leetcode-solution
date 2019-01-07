class Solution {
    public String reverseVowels(String s) {
        if(s==" "){
            return new String(" ");
        }else if(s==""){
            return new String("");
        }
        int size=s.length();
        int i=0,j=size-1;
        char[] re=new char[size];
        boolean tag_f=false,tag_e=false;
        while(i<j){
            if(isVoWels(s.charAt(i))){
                tag_f=true;
            }else{
                re[i]=s.charAt(i);
                i++;
            }
            if(isVoWels(s.charAt(j))){
                tag_e=true;
            }else{
                re[j]=s.charAt(j);
                j--;
            }
            if(tag_e&&tag_f){
                re[i]=s.charAt(j);
                re[j]=s.charAt(i);
                i++;
                j--;
                tag_e=false;tag_f=false;
            }

        }
        String result=new String(re);
        return result;

    }
    public boolean isVoWels(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||
        a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){
            return true;
        }else{
            return false;
        }
    }
}
/*
unknown bug for inputting "" or" "--->"\u0000"??? 
*/
public class problem345{
    public static void main(String[] args){
        String s="leetcode";
        Solution test=new Solution();
        System.out.println(test.reverseVowels(s));
    }
}