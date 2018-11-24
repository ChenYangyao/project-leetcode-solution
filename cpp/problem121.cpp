#include "mystd.h"
#include "climits"
using namespace std;

/**
 * naive solution, nested loop
 * Time complexity:  Theta( n^2 ), constant space complexity
 */
class Solution{
public:
    int maxProfit(vector<int> &prices){
        int n = prices.size(), max_profit = 0;
        for (int i = 0; i < n ; ++i){
            for (int j = i+1; j < n; ++j){
                max_profit = max( max_profit, prices[j] - prices[i] );
            }
        }
        return max_profit;
    }
};

/**
 * solution using split-merger paradigm
 *
 * The point is that, for any array with central index c, the maximal profit
 * must be achieved in one the following three cases:
 * (1) buy before c, sell when or after c
 * (2) buy and sell before c
 * (3) but and sell when or after c
 * Therefore we direcly calculate the maximal profit of (1), recursively calculate
 * those of (2) and (3), and eventually compare them.
 *
 * Time complexity: O(n*logn), space complexity: Theta(logn)
 */
class Solution2{
public:
    int maxProfit(vector<int> &prices){
        return maxProfit( prices, 0, prices.size() );
    }
    int maxProfit(vector<int> &prices, int l, int r){
        if( r - l <= 1 ) return 0;
        int c = l + (r-l)/2;
        int c_profit = findMaxCenteredAt(prices, c, l, r),
            l_profit = maxProfit(prices, l, c),
            r_profit = maxProfit(prices, c+1, r);
        return max(max( c_profit, l_profit ), r_profit);
    }
    int findMaxCenteredAt(vector<int> &prices, int c, int l, int r){
        int lmin = INT_MAX, rmax = INT_MIN;
        for (int i = c; i < r; ++i) rmax = max(rmax, prices[i]);
        for (int i = l; i <= c; ++i) lmin = min(lmin, prices[i]);
        return rmax - lmin;
    }
};


/**
 * solution, one loop
 *
 * This is the modified version of the first solution. When passing through
 * the array, temporary minimum that have encountered is kept. The maximal
 * profit, must be a price of a day minus the minimal prices before it.
 *
 * Time complexity:  Theta( n ), constant space complexity
 * References: Leetcode user solution. Thanks Ziyang for recommendation.
 */
class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        if( prices.empty() ) return 0;
        int localmin = prices[0], max_profit = 0;
        for(auto & price: prices)
            if( price < localmin )
                localmin = price;
            else
                max_profit = max(max_profit, price - localmin);
        return max_profit;
    }
};



int main(int argc, char const *argv[]){
    // test by the example in Leetcode
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;
    cout << sol.maxProfit(prices) << endl;
    cout << sol2.maxProfit(prices) << endl;
    cout << sol3.maxProfit(prices) << endl;
    return 0;
}
