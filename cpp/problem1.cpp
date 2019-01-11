#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * solution by using hash-set (not hash-map)
 * 
 * Each element, e, of input is gradually added into the hash-set, after
 * checking whether its complement, c = target - e, has already been in 
 * hash-set.
 * Once we are sure that c is in the hash-set, we linearly search the 
 * input array to find the index c.
 *
 * Hash-set saves half of memory compared with the hash-map, but will not
 * obviously increase the time cost.
 * Time: O(n); Space: O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
 		unordered_set<int> s;
        for (int i = 0, n = nums.size(); i < n; ++i){
        	if( s.find( target - nums[i] ) != s.end() ){
        		for (int j = 0, tar = target-nums[i]; j < i; ++j)
        		if( nums[j] == tar ) return {j,i};
        	}
        	s.emplace( nums[i] );
        }
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// case in Leetcode Problem
	vector<int> nums = {2,7,11,15};
	MYFILE::print_range( sol.twoSum(nums, 9) ) << endl;

	return 0;
}