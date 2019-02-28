class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length())return false;
        int size=s.length();
        if(size==0)return true;
        int[] temp1=GetCharacterForStr(s, size);  
        int[] temp2=GetCharacterForStr(t, size);
        for(int i=0;i<temp1.length;i++){
            if(temp1[i]!=temp2[i])return false;
        }   
        return true;
    }
    // !!! attention :This function is just valid for lowercases letters

    // valid function for all kind of situation need:
    // change  "HashNode[] hashForStr=new HashNode[26]"---to----> Map(S.charAt(i),HashNode)
    // I will do it later
    public int[] GetCharacterForStr(String s,int size){
        class HashNode{
            public int count;
            public int index;
            public HashNode(int x,int y){
                count=x;index=y;
            }
        }
        // count --->the times of appearing
        //index---> index of fist occuring
        HashNode[] hashForStr=new HashNode[26];
        int[] CharacterForS=new int[size];
        // element in CharactrForS is the order of char that first occur in string S
        //Example:
        //s="paper"---->character={0,1,0,2,3} 
        for(int i=0;i<hashForStr.length;i++){
            hashForStr[i]=new HashNode(0, 0);
        }
        hashForStr[(int)(s.charAt(0)-'a')]=new HashNode(1, 0);
        CharacterForS[0]=0;
        int last=0; 
        for(int i=1;i<size;i++){
            if(hashForStr[(int)(s.charAt(i)-'a')].count==0){
                CharacterForS[i]=++last;
                hashForStr[(int)(s.charAt(i)-'a')].count++;
                hashForStr[(int)(s.charAt(i)-'a')].index=i;
            }else{
                CharacterForS[i]=hashForStr[(int)(s.charAt(i)-'a')].index;
            }
        }
        return CharacterForS;
    }
}
public class problem205{
     public static void main(String args[]){
         Solution test=new Solution();
         /*
         String s="banana";
         int[] temp=test.GetCharacterForStr(s, s.length());
         for(int item:temp){
             System.out.println(item);
         }
         */
        System.out.println(test.isIsomorphic("paper", "title"));
    }
}