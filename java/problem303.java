class NumArray {
    int[] temp_num;

    public NumArray(int[] nums) {
        if(nums.length==0) {temp_num=null;return;}
        temp_num=new int[nums.length];
        temp_num[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            temp_num[i]=temp_num[i-1]+nums[i];
        }
    }
    public int sumRange(int i, int j) {
        if(temp_num==null)return 0;
        return i==0?temp_num[j]:temp_num[j]-temp_num[i-1];
    }
    
}


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */