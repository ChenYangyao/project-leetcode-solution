class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int filled = 0;
        for(auto num: nums){
            if( num ) nums[filled++] = num;
        }
        fill( nums.begin() + filled, nums.end(), 0 );
    }
};


class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int filled = 0;
        for ( int n = nums.size(); filled < n; ++filled)
            if( ! nums[filled] ) break;
        for ( int i = filled + 1, n = nums.size(); i < n; ++i ){
            if( nums[i] ){
                nums[filled++] = nums[i];
                nums[i] = 0;
            }
        }
    }
};
