import java.util.Vector;
import java.lang.Integer;
class Solution{
    //one source dijkstra algorithm 
    public static int rabbitCrossRiver(int n,int m,Vector<Integer> x,Vector<Integer> y){
        //create connect matrix
        //weight==0 or =1
        int size=n+2;
        System.out.println(size);
        int[][] connectMatrix=new int[size][size];
        //System.out.println(connectMatrix[0][0]);        
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                connectMatrix[i][j]=Integer.MAX_VALUE;
            }
        }
        for(int i=0;i<size;i++){
            for(int j=1;j<4;j++){
                if(i+j<size)connectMatrix[i][i+j]=1;
            }
        }
        for(int i=0;i<x.size();i++){
            connectMatrix[x.get(i)][y.get(i)]=0;
        }
        /*
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
               System.out.print(connectMatrix[i][j]);
               System.out.print(';');
            }
            System.out.println();
        }*/

        //implement Dijkstra algorihtm
        int[] dist=new int[size-1];
        boolean[] Solved_set=new boolean[size-1];
        int tag=0;
        for(int i=0;i<dist.length;i++){
            dist[i]=connectMatrix[0][i+1];
            //System.out.println(dist[i]);
        }
        while(tag<Solved_set.length){
            int index=Find_min_index(Solved_set, dist);
            System.out.println(index);
            Solved_set[index]=true;
            tag++;
            for(int i=0;i<dist.length;i++){
                if(!Solved_set[i]){
                    int temp=dist[index]+connectMatrix[index+1][i+1];;
                    if(temp<0){
                        temp=Integer.MAX_VALUE;
                    }
                    if(temp<dist[i]){
                        dist[i]=temp;
                    }
                }
            }
        }
        for(int i=0;i<dist.length;i++){
            System.out.println(dist[i]);
            System.out.println(';');
            if(i==dist.length-1)System.out.println("_____end____");
        }
        return dist[dist.length-1];
        
    }
    private static int  Find_min_index(boolean[] Solved_set,int[] dist){
        int value=Integer.MAX_VALUE;
        int index=-1;
        for(int i=0;i<dist.length;i++){
            if(!Solved_set[i]&&dist[i]<value){
                index=i;value=dist[i];
            }
        }
        return index;
    }

}

public class problem_1{
     public static void main(String args[]){
         Solution test=new Solution();
         int n=8;
         int m=3;
         Vector<Integer> x=new Vector<Integer>();
         Vector<Integer> y=new Vector<Integer>();
         x.add(1);x.add(3);x.add(6);
         y.add(4);y.add(5);y.add(8);
         System.out.println(test.rabbitCrossRiver(n, m, x, y));
    }
}