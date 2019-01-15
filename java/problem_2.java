import java.util.*;
class Solution{

    public int random5(){
        int x,y;
        x=random3();y=random3();
        while(x*y!=0){
            x=random3();y=random3();
        }
        int[] result={0,1,2,3,-1,-1,4};
        return result[3*x+y];

    }

    private int random3(){
        int temp=(int)(Math.random()*(3));
        return temp;
    }
}
public class problem_2{
     public static void main(String args[]){
         Solution test=new Solution();
         int[] tag=new int[5];
         int index=100000;
         while(index>=0){
             tag[test.random5()]++;
             index--;
         }
         for(int i=0;i<5;i++)System.out.println(tag[i]);   
    }
}