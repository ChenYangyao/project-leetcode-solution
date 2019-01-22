class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int size=s.length();
        boolean tag=false;
        for(int i=1;i<size;i++){
            tag=false;
            if(size%i==0){//the length of substing must be the factor of total length
                tag=true;
                for(int j=0;j<size/i-1;j++){//check substring(0--->i)
                    for(int k=0;k<i;k++){
                        if(s.charAt(k)!=s.charAt(k+(j+1)*i)){
                            tag=false;
                            break;
                        }
                    }
                    if(!tag){
                        break;
                    }
                }
            }
            if(tag){
                break;
            }
        }
        return tag;
        
    }
}