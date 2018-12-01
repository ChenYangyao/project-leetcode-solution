#include "mystd.h"
using namespace std;


/**
 * this solution may not be sensible, since in the worst case it consumes
 * 2^n computaon.
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


/**
 * stairs are more or less like a graph, where each node is connectect to the following two
 *
 * Typically the Dijkstra-like algorithm can be used. Here the weights are attached on the nodes, not edges.
 * Also we just need to know the best path to the final, not to all nodes.
 * So we gradually update the best pathes, using the previous best pathes.
 *
 * This takes Theta(n) time, and constant memory.
 */
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int i1 = 0, i2 = 1, cost1 = cost[i1], cost2 = cost[i2];
        cost.push_back(0);
        while( i1 < n - 2 ){
            cost1 = min( cost1, cost2 ) + cost[ i1 + 2 ];
            cost2 = min( cost2, cost1 ) + cost[ i2 + 2 ];
            i1 += 2;
            i2 += 2;
        }
        return min(cost1, cost2);
    }
};


int main(int argc, char const *argv[])
{
    // example in Leetcode Problem
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;

    Solution2 sol2;
    cout << sol2.minCostClimbingStairs(cost) << endl;

    return 0;
}
