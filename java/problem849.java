class Solution {
    public int maxDistToClosest(int[] seats) {
        if(seats.length<2){
            return 0;
        }
        int i=0,j=0;
        boolean tag=false; 
        int max_dis=0;
        while(j<seats.length&&i<seats.length){
            if(seats[i]!=0){
                i++;
                j++;
            }else{
                tag=true;
            }
            if(tag){
                if(seats[j]==0&&j!=seats.length-1){
                    j++;
                }else{
                    tag=false;
                    if(i==0){
                        if((j-i)>max_dis){
                            max_dis=j-i;
                        }
                    }else if(j==seats.length-1&&seats[j]==0){
                        if((j-i+1)>max_dis){
                            max_dis=j-i+1;
                        }
                        break;
                    }else{
                        if((j-i+1)/2>max_dis){
                            max_dis=(j-i+1)/2;
                        }
                    }
                    i=j;
                }
            }
        } 
        return max_dis;     
    }
}