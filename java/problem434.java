class Solution {
    public int countSegments(String s) {
        if(s.length()==0)return 0;
        boolean tag=false;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(!tag&&s.charAt(i)!=' '){
                tag=true;
            }
            if(tag&&(s.charAt(i)==' '||i==s.length()-1)){
                result++;
                tag=false;
            }
        }
        return result;
    }
}