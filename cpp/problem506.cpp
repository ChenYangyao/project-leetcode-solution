class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 )return vector<string>();
        vector<int> indx(n);
        for (int i = 0; i < n; ++i) indx[i] = i;
        sort( indx.begin(), indx.end(), [&nums]( int i, int j ){ return nums[i] > nums[j];  } );

        vector<string> res(n);
        int i = 0;
        res[ indx[ i++ ] ] = "Gold Medal";
        if( i == n ) return res;
        res[ indx[ i++ ] ] = "Silver Medal";
        if( i == n ) return res;
        res[ indx[ i++ ] ] = "Bronze Medal";
        while( i < n ){
            res[ indx[ i ] ] = to_string(i+1);
            ++i;
        }
        return res;
    }
};
