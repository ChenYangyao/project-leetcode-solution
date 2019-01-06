#include <mystd.h>
using namespace std;

/**
 * -------------------------------------------------------------------------
 * This is more or less similar with Problem 746. Min Cost Climbing Stairs
 * E.g. see. https://leetcode.com/problems/min-cost-climbing-stairs/
 * But here the link-length for this graph is 3, so we need three temporary
 * space to keep the best result ever found in the linear traversal.
 *
 * Solution time cost: Theta( nums.size() ), space cost: constant
 *
 * Author: Yangyao, 2019/01/05
 * -------------------------------------------------------------------------
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


/**
 * -------------------------------------------------------------------------
 * As suggested by Ziyang, there is a more elegant implementation.
 * For houses that conntected to 1 neighbor, we only need to keep
 * record of the last two best results ever found during iteration.
 * (see Swift solution for the detail.)
 * 
 * Here is a more general solution, although it might be a little bit 
 * inefficient. The template argument NLink represent how many neighbor
 * houses are connected by the security system.
 * The solution for Leetcode problem (NLink = 1) can be obtained by 
 *          BestRob<1>().get(nums);
 * Solution with other link-length NLink can be obtained by
 *          BestRob<NLink>.get(nums);
 *
 * The template version is fast due to the compiling-time determination
 * of NLink. For flexibility we also provide a run-time version, with 
 * template argument to be -1, but NLink passed through constructor at 
 * run-time. The calling can be like (where NLink now can be a run-time 
 * variable):
 *          BestRob<-1>(NLink).get(nums);
 *
 * Author: Yangyao, 2019/01/07
 * -------------------------------------------------------------------------
 */
template<int NLink = 1>
class BestRob{
public:
    int get( vector<int> &nums ){
        int cur;
        for (int i = 0, n = nums.size(); i < n; ++i){
            cur = max( best[ (i+1)%(NLink+1) ] + nums[i], best[ (i)%(NLink+1) ] );
            best[ (i+1)%(NLink+1) ] = cur;
        }
        return *max_element(best, best+NLink+1);
    }
protected:
    int best[ NLink + 1 ] = {};
};

template<>
class BestRob<-1>
{
public:
    BestRob(int _NLink): NLink(_NLink), best(NLink + 1, 0){}
    int get( vector<int> &nums ){
        int cur;
        for (int i = 0, n = nums.size(); i < n; ++i){
            cur = max( best[ (i+1)%(NLink+1) ] + nums[i], best[ (i)%(NLink+1) ] );
            best[ (i+1)%(NLink+1) ] = cur;
        }
        return *max_element(best.data(), best.data()+NLink+1);
    }
protected:
    int NLink;
    vector<int> best;
};

class Solution2{
public:
    int rob(vector<int>& nums) {
        return BestRob<-1>(1).get( nums );
    }
};




int main(int argc, char const *argv[]){
	Solution sol;
    Solution2 sol2;
	
	// cases in Leetcode problem
	vector<int> nums = {1,2,3,1 };
	cout << sol.rob( nums ) << endl;
    cout << sol2.rob( nums ) << endl;

	nums.assign({ 2,7,9,3,1 });
	cout << sol.rob( nums ) << endl;
    cout << sol2.rob( nums ) << endl;

	// case in Leetcode judgement
	nums.assign({1,3,1});
	cout << sol.rob( nums ) << endl;
    cout << sol2.rob( nums ) << endl;
\
	return 0;
}