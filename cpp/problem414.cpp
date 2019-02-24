#include <mystd.h>
using namespace MYSTD;
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long x1 = LONG_MIN+2, x2 = LONG_MIN+1, x3 = LONG_MIN;
        for(auto x: nums){
            if( x > x1 ){ x3 = x2; x2 = x1; x1 = x; }
            else if( x == x1 ) continue;
            else if( x > x2 ){ x3 = x2; x2 = x; }
            else if( x == x2 ) continue;
            else if( x > x3 ) x3 = x;
        }
        return x3 < INT_MIN?x1:x3;
    }  
};

int main(int argc, char const *argv[]){
    Solution sol;

    vector<int> nums;

    // cases in Leetcode Problem
    nums = {3,2,1};
    cout << sol.thirdMax(nums) << endl;
    nums = {1,2};
    cout << sol.thirdMax(nums) << endl;
    nums = {2,2,3,1};
    cout << sol.thirdMax(nums) << endl;

    // other extreme cases
    nums = {2,1,2};
    cout << sol.thirdMax(nums) << endl;
    nums = {2,2,3,3};
    cout << sol.thirdMax(nums) << endl;
    nums = {2,2,3,3,1};
    cout << sol.thirdMax(nums) << endl;
    return 0;
}