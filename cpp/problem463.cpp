class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if( ! grid.size() ) return 0;
        int nrow = grid.size(), ncol = grid[0].size();
        int perim = 0;

        for (int i = 0; i < nrow; ++i)
        for (int j = 0; j < ncol; ++j)
            if( grid[i][j] ){
                perim += 4;
                if( i > 0 && grid[i-1][j] ) perim -= 2;
                if( j > 0 && grid[i][j-1] ) perim -= 2;
            }
        return perim;
    }
};
