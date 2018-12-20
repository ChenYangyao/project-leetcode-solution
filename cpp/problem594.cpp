#include <mystd.h>
using namespace std;

/**
 * solution by counting the appearance of each unique element in the input sequence.
 *
 * if val appears n times and val + 1 also appears m times, m + n could compete with 
 * the result that has been obtained. 
 */
class Solution {
public:
	typedef unordered_map<int, int> counter_t;
    int findLHS(vector<int>& nums) {
        counter_t counter;
        for(auto i: nums) ++counter[i];
        int lhs = 0;
        for(auto & pair: counter){
        	auto it = counter.find( pair.first + 1 );
        	if( it != counter.end() ) lhs = max(lhs, it->second + pair.second);
        }
        return lhs;
    }
};

int main(int argc, char const *argv[])
{
	// test case in Leetcode problem
	vector<int> nums = {1,3,2,2,5,2,3,7};
	Solution sol;
	cout << sol.findLHS( nums ) << endl;
	return 0;
}