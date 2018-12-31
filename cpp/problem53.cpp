#include <mystd.h>
using namespace std;

/**
 * direct solution ( similar to the question: best time to buy and sell stock )
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int num_accum = 0, num_bottom = 0, res = INT_MIN;
        for(auto num: nums){
        	num_accum += num;
        	res = max( res, num_accum - num_bottom );
        	num_bottom = min( num_bottom, num_accum );
        }
        return res;
    }
};

/**
 * divide-and-conquer algorithm
 * 
 * Description:
 * for each array [c1, c2, ..., ci, ..., cn], the max-subarray can be one of the following cases:
 * (i) a subarray that passes the center element ci: [ cj, ..., ci, ..., ck ] (j>=1, k <= n).
 * (ii) the max-subarray in the left piece [ c1, ..., c(i-1) ].
 * (iii) the max-subarray in the right piece [ c(i+1), ..., cn ].
 * Therefore each time we divide the array into two, recursively compute the max-subarray in left 
 * piece and right piece, compare them with the max-subarray that passes the center element.
 */
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
	    return maxSubArray( nums, 0, nums.size() );
    }
    int maxSubArray(vector<int> &nums, int b, int e) {
    	if( b == e ) return INT_MIN;
    	int c = b + (e-b)/2;
    	int maxl = maxSubArray( nums, b, c ), maxr = maxSubArray(nums, c+1, e),
    		maxc = maxContainingCenter( nums, b, c, e );
    	return (maxl > maxr)? max( maxl, maxc ) : max( maxr, maxc );
    }
    /**
     * find the max-subarray with the restriction that it should pass the center element nums[c]
     */
    int maxContainingCenter( vector<int> &nums, int b, int c, int e ) {
    	int maxl = 0, maxr = 0, accum = 0;
    	for (int i = c - 1; i >= b; --i){
    		accum += nums[i];
    		maxl = max( maxl, accum );
    	}
    	accum = 0;
    	for (int i = c + 1; i < e; ++i){
    		accum += nums[i];
    		maxr = max(maxr, accum);
    	}
    	return maxl + maxr + nums[c];
    }
};


int main(int argc, char const *argv[])
{
	Solution sol;
	Solution2 sol2;

	// an example in Leetcode website
	vector<int> v =  {-2,1,-3,4,-1,2,1,-5,4};
	cout << sol.maxSubArray( v ) << endl;
	cout << sol2.maxSubArray( v ) << endl;
	return 0;
}
