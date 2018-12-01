#include "mystd.h"
using namespace std;

/**
 * overlap in two-dimension space <=> overlap in each sub-dimension
 */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isOverlapInOneDimension( rec1[0], rec1[2], rec2[0], rec2[2] )
            && isOverlapInOneDimension( rec1[1], rec1[3], rec2[1], rec2[3] );
    }
    bool isOverlapInOneDimension(int x1, int x2, int x3, int x4){
        if( x1 <= x3  ) return x3 < x2;
        else return x1 < x4;
    }
};


int main(int argc, char const *argv[])
{
    // test example in Leetcode Problem
    vector<int> rec1 = {0,0,2,2}, rec2 = {1,1,3,3},
        rec3 = {0,0,1,1}, rec4 = {1,0,2,1};
    Solution sol;

    cout << sol.isRectangleOverlap(rec1, rec2) << endl;
    cout << sol.isRectangleOverlap(rec3, rec4) << endl;
    return 0;
}
