#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by direct sum of each sub-array
 * Note that sum[n-k...n) = sum[n-k-1...n-1) + nums[n] - nums[n-k-1],
 * which means sum of each sub-array can be recursively obtain from 
 * previous sub-array, so the time complexity is independent with k.
 * 
 * Space: constant; Time: Theta(nums.length).
 */ 
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = accumulate( nums.data(), nums.data() + k, 0 );
        
        int i = k - 1, sum = maxSum; 
        while( ++i < nums.size() ){
            sum += nums[i] - nums[i-k];
            maxSum = max(sum, maxSum);
        }

        return maxSum / double(k);
    }
};


int main(int argc, char const *argv[]){
    // case in Leetcode Problem
    vector<int> nums = {1,12,-5,-6,50,3};
    Solution sol;
    cout << sol.findMaxAverage( nums, 4 ) << endl;
    return 0;
}
