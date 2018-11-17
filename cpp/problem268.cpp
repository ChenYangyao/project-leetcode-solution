#include "mystd.h"
using namespace std;

/**
 * solution by getting the summation from 0 to n,
 *  and then subtracting each appeared one
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_0_to_n = (1+n)*n/2;
        for(auto num: nums){
            sum_0_to_n -= num;
        }
        return sum_0_to_n;
    }
};


int main(int argc, char const *argv[])
{
    // test with the example to Leetcode website
    vector<int> v1 = {9,6,4,2,3,5,7,0,1}, v2 = {3,0,1};
    Solution sol;
    cout << sol.missingNumber(v1) << " and " << sol.missingNumber(v2) << endl;
    return 0;
}
