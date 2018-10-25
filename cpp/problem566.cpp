class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0 = nums.size(), c0 = nums[0].size(), rc0 = r0*c0, rc = r*c;
        if( rc != rc0 ) return nums;
        auto res = vector<vector<int> >( r, vector<int>(c) );
        int indx;
        for (int i = 0; i < r0; ++i){
            for (int j = 0; j < c0; ++j){
                indx = i*c0 + j;
                res[ indx/c ][ indx%c ] = nums[i][j];
            }
        }
        return res;
    }
};
