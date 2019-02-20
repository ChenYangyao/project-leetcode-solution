import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int N, int K){
        if(times==null){
            return -1;
        }else if(times.length==0){
             return -1;
        }
        //construct the graph connect list((sorce,(target,dis)))
        Map<Integer,Map<Integer,Integer>> route=new HashMap<>();
        for(int[] time:times){
            Map<Integer,Integer> tag_dis=route.get(time[0]);
            if(tag_dis==null){
                tag_dis=new HashMap<>();
                route.put(time[0],tag_dis);
            }
            Integer dis=tag_dis.get(time[1]);
            if(dis==null||dis>time[2]){
                tag_dis.put(time[1],time[2]);
            }
        }
        //test the graph connect list

        /*
        for(Integer key:route.keySet()){
            System.out.println("key:"+key+"value:"+route.get(key));
        }*/

        //implement the djikstra's algorithm
        //Given that N~100,heap or binary tree is not needed
        //kink_num~6000---N*N=10000

        int[] dist=new int[N];
        for(int i=0;i<dist.length;i++) dist[i]=-1 ;
        dist[K-1]=0;
        boolean[] solved_set=new boolean[N];solved_set[K-1]=true;        

        Map<Integer,Integer> begin_node=route.get(K);
        if(begin_node==null){
            return -1;
        }
        for(Integer key:begin_node.keySet()){
            dist[key.intValue()-1]=(begin_node.get(key)).intValue();
        }
        int num_cal=0;
        while(num_cal<N-1){
            int min=Integer.MAX_VALUE;
            int win_index=N;
            for(int i=0;i<dist.length;i++){
                if(dist[i]!=-1 && !solved_set[i] && dist[i]<min){
                    win_index=i;
                    min=dist[i];
                }
            }
            if(win_index<N){
                solved_set[win_index]=true;
                for(int i=0;i<dist.length;i++){
                    if(!solved_set[i]){
                        Map<Integer,Integer> temp=route.get(Integer.valueOf(win_index+1));
                        int d_temp=Integer.MAX_VALUE;
                        if(temp!=null){
                            Integer tag=temp.get(Integer.valueOf(i)+1);
                            if(tag!=null){
                                d_temp=tag.intValue();
                            }
                        }
                        if(d_temp!=Integer.MAX_VALUE && (d_temp+min <dist[i] || dist[i]==-1) ){
                            dist[i]=d_temp+min;
                        }
                    }
                }
            }
            num_cal++;
        }
        for(boolean temp:solved_set){
            if(!temp)return -1;
        }

        int result=dist[0];
        for(int temp:dist){
            if(temp>result) result=temp;
        }
        return result;
    }
}