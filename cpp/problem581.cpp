#include <mystd.h>
using namespace MYSTD;
using namespace std;

/** 
 * solution by first finding the largest index i where
 * nums[i] = min( nums[i...] ), then locating the smallest
 * index j where nums[j] = max( nums[...j] ). Then the array
 * between i and j need to be sorted.
 * Time: linear with nums.length.
 * Space: linear with nums.length.
 * Author: Yangyao, 2019/02/23
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if( nums.empty() ) return 0;  

        vector<int> temps(nums.size()); 
        temps[0] = nums[0];
        for(int i=1, n=nums.size(); i<n; ++i)
            temps[i] = max( nums[i], temps[i-1] );
        int i=nums.size()-1;
        for(; i>=0; --i)
            if( nums[i] != temps[i] )break;
        if( i < 0 ) return 0;
        temps[i] = nums[i];
        for(int j=i-1; j>=0; --j)
            temps[j] = min(temps[j+1],nums[j]);
        int j = 0;
        for(; j<i; ++j){
            if( nums[j] != temps[j] )break;
        }
        return i-j+1;
    }
};

/** 
 * solution by first find the first peak i and the last valley j
 * of the input.
 * e.g. 
 *     nums = [ 1,2,3,4,3,2,1,0,-1,0,1,2 ],
 * the first peak is nums[3] = 4, the last valley is nums[-4] = -1.
 * Then we gradually borden the range nums[i...j] such that 
 * nums[i] <= min( nums[i...j] ) and nums[j] >= max( nums[i...j] ).
 * Time: linear with nums.length.
 * Space: constant.
 * Author: Yangyao, 2019/02/23
 */
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        while( i + 1 < n && nums[i] <= nums[i+1]  ) ++i;
        if( i >= n-1 ) return 0;
        while( j - 1 > i && nums[j-1] <= nums[j] ) --j;
        for(int k = i, u = j; k <= u; ++k){
            while( i >= 0 && nums[k] < nums[i] ) --i;
            while( j < n && nums[k] > nums[j] ) ++j;
        }
        return j - i - 1;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // case in Leetcode Problem
    vector<int> nums = {2,6,4,8,10,9,15};
    cout << sol.findUnsortedSubarray(nums) << endl;
    cout << sol2.findUnsortedSubarray(nums) << endl;

    // case in Leetcode judge-system
    nums = {1,2,3,3,3};
    cout << sol.findUnsortedSubarray(nums) << endl;
    cout << sol2.findUnsortedSubarray(nums) << endl;
    return 0;
}