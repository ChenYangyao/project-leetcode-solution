#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int nx = grid.size(), ny = grid[0].size();
        vector<int> x_maxs(nx,0), y_maxs(ny,0);
        int ct = 0, temp;
        for (int i = 0; i < nx; ++i)
            for (int j = 0; j < ny; ++j){
                temp = grid[i][j];
                if( temp ) ++ct;
                if( temp > x_maxs[i] ) x_maxs[i] = temp;
                if( temp > y_maxs[j] ) y_maxs[j] = temp;
            }
        return ct + accumulate( x_maxs.begin(), x_maxs.end(), 0 ) + accumulate( y_maxs.begin(), y_maxs.end(), 0 );
    }
};
