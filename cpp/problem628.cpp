#include "mystd.h"
using namespace std;

/**
 * solution by finding several maximal positive numbers and several minimal
 * negative numbers.
 *
 * This solution can deal with any number of operands specified by nop.
 *
 * The procedure is:
 * - specify number of operands by 'nop'.
 * - in the one-run loop, find biggest nop positive numbers and nop negive numbers,
 *      by the way like the insert-sort (if nop is large enough, we may use heap)
 * - find the result in the 2*nop numbers.
 *
 * time - linear with nums.size()
 * space - linear with nop
 */
class Solution {
public:
    const int nop;
    Solution(int _nop = 3):nop(_nop){}
    int maximumProduct(vector<int>& nums) {
        int maxs[nop+1]; fill_n( maxs, nop, INT_MIN );
        int mins[nop+1]; fill_n( mins, nop, INT_MAX );
        for(auto num: nums){
            int i = nop-1;
            while( i >= 0 && num > maxs[i] ){
                maxs[i+1] = maxs[i];
                --i;
            }
            maxs[i+1] = num;
            i = nop-1;
            while( i >= 0 && num < mins[i] ){
                mins[i+1] = mins[i];
                --i;
            }
            mins[i+1] = num;
        }
        int npositive = 0, nnegative = 0;
        while( npositive < nop && maxs[npositive] >= 0 ) ++npositive;
        while( nnegative < nop && mins[nnegative] < 0 ) ++nnegative;

        int res = INT_MIN;
        for (int i = nop - nnegative; i <= npositive; ++i){
            int tempres = 1;
            for (int j = 0; j < i; ++j) tempres *= maxs[j];
            for (int j = 0; j < nop-i; ++j) tempres *= mins[j];
            res = max(res, tempres);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4}, nums2 = {-5,-4,0,1,2,3}, nums3 = {-1,-2,-3}, nums4 = {1,2,3};

    Solution sol;
    cout << sol.maximumProduct(nums) << endl;
    cout << sol.maximumProduct(nums2) << endl;
    cout << sol.maximumProduct(nums3) << endl;
    cout << sol.maximumProduct(nums4) << endl;

    Solution sol_for_4operand(4);
    cout << sol_for_4operand.maximumProduct(nums2) << endl;

    Solution sol_for_6operand(6);
    cout << sol_for_6operand.maximumProduct(nums2) << endl;
    return 0;
}
