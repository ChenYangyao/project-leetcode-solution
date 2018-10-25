#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        size_t nrow = grid.size(), ncol = grid[0].size();
        int temp;
        vector<int> row_maxs( nrow, 0 ), col_maxs( ncol, 0 );
        for( size_t i = 0; i < nrow; ++i )
            for ( size_t j = 0; j < ncol; ++j){
                temp = grid[i][j];
                if( temp > row_maxs[i] ) row_maxs[i] = temp;
                if( temp > col_maxs[j] ) col_maxs[j] = temp;
            }

        temp = 0;
        for( size_t i = 0; i < nrow; ++i )
            for ( size_t j = 0; j < ncol; ++j){
                temp += row_maxs[i] > col_maxs[j] ? (col_maxs[j] - grid[i][j]) : ( row_maxs[i] - grid[i][j] );
            }
        return temp;
    }
};
