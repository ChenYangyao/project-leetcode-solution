#include "mystd.h"
using namespace std;


/**
 * this solution may not be sensible, since in the worst case it consumes
 * 2^n computation.
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        len = cost.size();
        int cost1 = minCostClimbingStairs(cost, 0),
            cost2 = minCostClimbingStairs(cost, 1);
        return min(cost1, cost2);
    }
    int minCostClimbingStairs(vector<int>& cost, int beg) {
        if( beg >= len ){ return 0; }
        if( beg >= len - 2  ){ return cost[beg]; }

        if( cost[ beg + 1 ] >= cost[ beg + 2 ] )
            return cost[beg] + minCostClimbingStairs(cost, beg + 2);
        else{
            int cost1 = minCostClimbingStairs( cost, beg + 3 ),
            cost2 = minCostClimbingStairs( cost, beg + 4 );
            return cost[beg] + min( cost[beg+1] + cost1, cost[beg+2] + cost2 );
        }
    }
protected:
    int len;
};


int main(int argc, char const *argv[])
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
