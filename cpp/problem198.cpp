#include <mystd.h>
using namespace std;

/**
 * This is more or less similar with Problem 746. Min Cost Climbing Stairs
 * E.g. see. https://leetcode.com/problems/min-cost-climbing-stairs/
 * But here the link-length for this graph is 3, so we need three temporary
 * space to keep the best result ever found in the linear traversal.
 *
 * Solution time cost: Theta( nums.size() ), space cost: constant
 *
 * Author: Yangyao, 2019/01/05
 */
class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
    	if( n == 0 ) return 0;
    	if( n == 1 ) return nums[0];
    	if( n == 2 ) return max( nums[0], nums[1] );

    	// best[ N ] are the maximal gain ever found
    	// best[0], best[1] is valid maximal gain, while best[2] needs
    	// to be updated by best[0].
        int best[N] = {nums[0], nums[1], 0};
        int indx = 0, cur, next;
        while( true ){
        	cur = indx % N, next = (cur + 2) % N;
        	best[next] = max( best[next], best[cur] + nums[indx + 2] );
        	if( indx + 3 == n ) break;
        	best[cur] += nums[indx + 3];
        	++indx;
        }
        return max( best[ (cur + 1)%N ], best[ (cur + 2)%N ] );
    }
protected:
	const static int N = 3;
};


int main(int argc, char const *argv[]){
	Solution sol;
	
	// cases in Leetcode problem
	vector<int> nums = {1,2,3,1 };
	cout << sol.rob( nums ) << endl;

	nums.assign({ 2,7,9,3,1 });
	cout << sol.rob( nums ) << endl;

	// case in Leetcode judgement
	nums.assign({1,3,1});
	cout << sol.rob( nums ) << endl;

	return 0;
}