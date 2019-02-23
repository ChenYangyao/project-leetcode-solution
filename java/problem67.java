
class Solution {
    public String addBinary(String a, String b){
        StringBuilder result=new StringBuilder(); 
        int end_a=a.length()-1;int end_b=b.length()-1;
        int over_flow=0;
        while(end_a>=0||end_b>=0){
            int sum=over_flow;
            if(end_a>=0){
                sum+=a.charAt(end_a--)-'0';
            }
            if(end_b>=0){
                sum+=b.charAt(end_b--)-'0';   
            }
            result.append( sum % 2 );
            over_flow=sum/2;
        }
        if(over_flow!=0)result.append(over_flow);
        return result.reverse().toString();
        
    }
}