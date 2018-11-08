class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if( ops.empty() ) return m*n;

        int min1 = INT_MAX, min2 = INT_MAX;
        for(const auto & i: ops){
            min1 = min(i[0], min1);
            min2 = min(i[1], min2);
        }
        return min1*min2;
    }
};
