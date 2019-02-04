#include <mystd.h>
using namespace std;
using namespace MYSTD;


/**
 * solution by counting 5 as factors of numbers below n
 * Explanataion:
 * (i) it is easy to prove that, <= any positive number n, numbers that have
 *      factor 5 are more sparse than numbers that have factor 2. If a number 
 *      has a factor 5, we can always find a corresponding number that has a
 *      factor 2, product of which with 5 will produce a 0 at the tail of n!.
 * (ii) for any positive number n, if we write it as base-5 form, such as
 *      n = (base-5)xyz...pqr, then it is easy to show that there are xyz...pq
 *      number that has factor 5, xyz...p number that has factor 25 = (5x5),
 *      xyz... number that has factor 125 = (5x5x5), ...
 *      So by converting  the number n to base-5 form, we can easily show that
 *      total number of factor 5 is xyz...pq + xyz...p + xyz... + ...
 * Below is implementation of this idea.
 * 
 * Author: Yangyao, 2019/02/02
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt5 = 0;
        while(n /= 5) cnt5 += n;
        return cnt5;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    // examples in Leetcode Problem
    cout << sol.trailingZeroes( 3 ) << endl;
    cout << sol.trailingZeroes( 5 ) << endl;

    // a large number n where n! is not feasible to be calculated
    cout << sol.trailingZeroes( 25100 ) << endl;

    return 0;
}




