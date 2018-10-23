class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, min_val = nums[0];
        for(auto num: nums){
            sum += num;
            if( num < min_val ) min_val = num;
        }
        return sum - min_val*nums.size();
    }
};
