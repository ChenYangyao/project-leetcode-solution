#include <mystd.h>
using namespace std;

/**
 * solution by directly calculating the left-sum and right-sum
 * 
 * The right-sum is initialized by first loop (by calling accumulate).
 * In each step of the (forward) second loop, the left sum is accumulated 
 * gradually, and the right-sum is subtracted gradually.
 * By definition, if we find at some point the left-sum == right-sum, the
 * currecnt index is returned as the answer.
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    	int rsum = std::accumulate(nums.begin(), nums.end(), 0),
    		lsum = 0;
    	for(auto &i: nums){
    		if( lsum == (rsum -= i) ) return &i - nums.data();
    		lsum += i;
    	}
    	return -1;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// test case in Leetcode Problem
	vector<int> nums = {1, 7, 3, 6, 5, 6};
	cout << sol.pivotIndex( nums ) << endl;
	nums.assign({1,2,3});
	cout << sol.pivotIndex( nums ) << endl;
	return 0;
}