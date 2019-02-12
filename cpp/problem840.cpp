#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * the only 8 possible magic squares
 * Here we use the position of 1 and 2, relative to 5 and 9, to index the 8 cases.
 * e.g. for the magic square
 *     6,7,2
 *     1,5,9
 *     8,3,4
 * the position of 1 (relative to 5) is (x1,y1) = (-1,0),
 * the position of 2 (relative to 9) is y2 = 1 (vertically).
 * so the index is (x1,y1,y2) = (M1, 0, 1), the name is magicM101.
 */ 
static vector<int> magicM101 = {6,7,2,1,5,9,8,3,4},
    magicM10M1 = {8,3,4,1,5,9,6,7,2},
    magic101 = {2,7,6,9,5,1,4,3,8},
    magic10M1 = {4,3,8,9,5,1,2,7,6},
    magic011 = {8,1,6,3,5,7,4,9,2},
    magic01M1 = {6,1,8,7,5,3,2,9,4},
    magic0M1M1 = {2,9,4,7,5,3,6,1,8},
    magic0M11 = {4,9,2,3,5,7,8,1,6};


/**
 * solution by directly comaparing each 3x3 square in the grid 
 * with one of the 8 possible magic squares.
 * 
 * Author: Yangyao Chen, 2010/02/02
 */ 
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cntMagic = 0;
        int m = grid.size() - 2, n = grid[0].size() - 2;
        // we first determine which magic square the 3x3 square could be
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j){
            if( grid[i+1][j+1] != 5 ) continue;     // center must be 5 for a magic square
            if( grid[i+1][j] == 1 ){                // (x1, y1) == (-1, 0)
                cntMagic += grid[i][j+2] == 2 ? 
                    isMagic( grid, i, j, magicM101) : isMagic( grid, i, j, magicM10M1);
            }else if( grid[i+1][j+2] == 1 ){        // (x1, y1) == (1, 0)
                cntMagic += grid[i][j] == 2 ? 
                    isMagic( grid, i, j, magic101): isMagic( grid, i, j, magic10M1 );
            }else if( grid[i][j+1] == 1 ){          // (x1, y1) == (0, 1)
                cntMagic += grid[i+2][j+2] == 2 ?
                    isMagic( grid, i, j, magic011): isMagic( grid, i, j, magic01M1 );
            }else{
                cntMagic += grid[i][j] == 2 ?       // (x1, y1) == (0, -1)
                    isMagic( grid, i, j, magic0M1M1): isMagic( grid, i, j, magic0M11 );
            }
        }
        return cntMagic;
    }
    /**
     * compare a 3x3 square 'grid[i...i+3, j...j+3]' with a certain magic square 'magic'
     */ 
    bool isMagic(vector<vector<int>> &grid, int i, int j, vector<int> &magic){
        int k = 0;
        for(int _i=0; _i<3; ++_i)
        for(int _j=0; _j<3; ++_j){
            if( grid[_i + i][_j + j] != magic[ k++ ] ) return false;   
        }
        return true;
    }
};



int main(int argc, char const *argv[]){
    Solution sol;

    // test case in Leetcode Problem
    vector<vector<int>> grid = { {4,3,8,4},{9,5,1,9},{2,7,6,2} };
    cout << sol.numMagicSquaresInside(grid) << endl;
    return 0;
}
