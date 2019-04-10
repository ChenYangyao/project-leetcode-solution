#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * mathematical way, extension of problem 268
 *
 * Let p appears twice and k is missing, sum of i for i in nums gives
 *		x = n(n+1) + p - k,   				...(1)
 * but sum of i^2 for i in nums gives
 *      y = n(n+1)(2n+1)/6 + p^2 - k^2.		...(2)
 * The unique solution of eqs set (1)(2) gives answer p and k.
 *
 * This passes Leetcode judgement, but leaves huge bug so that it should
 * not be used in real case. Since y ~ n^3, so it could not be safely 
 * contained by long integer (64 bits in most modern system).
 *
 * Time: O(n); no extra space.
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
  		long x = 0, y = 0, n = nums.size();
  		for(auto i: nums){
  			x += i;
  			y += i*i;
  		}
  		x -= n*(n+1)/2;
  		y -= n*(n+1)*(2*n+1)/6;
  		long z = y/x;
  		return vector<int>({ (z + x)/2, (z -  x)/2 });
    }
};

/**
 * solution that largely mimic problem 448, leaves a tag to indicate
 * the appearance of a number
 * 
 * If i appears, then nums[ abs(i)-1 ] is set to be -num[ abs(i)-1 ].
 * This is iteratively done for all number in nums.
 * If a number appears twice, we can detect the flip from negative to
 * positive, and let the negative unchanged.
 * Finally the only index that has a positive number indicate the 
 * missing number.
 *
 * Time: O(n); no extra space, but input is modified.
 * References: Leetcode Official Solution
 */
class Solution2{
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	int p, k;
  		for(auto i: nums){
  			int id = abs(i) - 1;
  			if( nums[id] < 0 ) p = id + 1;
  			else nums[id] = - nums[id];
  		}
  		for(auto &i: nums)
  			if( i > 0 ) k = int(&i-nums.data()) + 1;
  		return vector<int>({p, k});
    }	
};

/**
 * solution that only needs XOR operation and forward iteration
 *
 * This is particular useful when the input data structure only has forward
 * iterator (e.g. single linked list).
 *
 * Let the repeated number and missing number to be p and k, the idea is to
 * (1) find one bit that is different in p and k, e.g.
 *           xor = p^k
 *           rmbit = xor & ~(xor-1) 
 *                gives the right most different bit of p and k
 * (2) partition input nums into two sets, according to the bit found in (1)
 *     set or unset, e.g.
 * 			 num & rmbit == 0 for the first set, == rmbit for the second
 * (3) we know that one set must contain the missing number, another set 
 *     contains the repeated one. we can found them by XOR.
 * 
 * Time: O(n); no extra space
 * References: Leetcode Official Solution
 */
class Solution3{
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	// find  the rightmost different bit
    	int _xor = 0, n = nums.size();
    	for( int i = 1; i <= n; ++i ) _xor ^= i;
    	for(auto i: nums) _xor ^= i;
    	int rmbit = _xor & ~(_xor - 1);

    	// partion nums into two sets, according two the rmbit
    	// find missing/repeated number in each set
    	int _xor1 = 0, _xor2 = 0;
    	for( int i = 1; i <= n; ++i ){
    		if( i & rmbit ) _xor1 ^= i;
    		else _xor2 ^= i;
    	}
    	for(auto i: nums){
    		if( i & rmbit ) _xor1 ^= i;
    		else _xor2 ^= i;
    	}

    	// determine which is repeated
    	for(auto i: nums){
    		if( i == _xor1 ) return { _xor1, _xor2 };
    	}
    	return {_xor2, _xor1};
    }	
};


int main(int argc, char const *argv[]){
	Solution sol;
	Solution2 sol2;
	Solution3 sol3;
	
	// cases in Leetcode Problem
	vector<int> nums = {1,2,2,4};
	MYFILE::print_range( sol.findErrorNums(nums) ) << endl;
	MYFILE::print_range( sol3.findErrorNums(nums) ) << endl;
	MYFILE::print_range( sol2.findErrorNums(nums) ) << endl;

	nums.assign({10,9,8,7,6,5,4,3,7,1});
	MYFILE::print_range( sol.findErrorNums(nums) ) << endl;
	MYFILE::print_range( sol3.findErrorNums(nums) ) << endl;
	MYFILE::print_range( sol2.findErrorNums(nums) ) << endl;

	return 0;
}
