// Class: Area = 6 surface - overlap with neighbors
// Creat: Yangyao Chen, 2018/10/10
// References: Leetcode user solution
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                if( grid[i][j] ) area += 2 + grid[i][j]*4;
                if( i ) area -= min( grid[i][j], grid[i-1][j] )*2;
                if( j ) area -= min( grid[i][j], grid[i][j-1] )*2;
            }
        }
        return area;
    }
};
