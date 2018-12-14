#include <mystd.h>
using namespace std;

/**
 * a trivial question, simply solved by linear traversal
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    	if( nums.empty() ) return 0;
        int len = 1, res = 1;
        for (int i = 1, n = nums.size(); i < n; ++i){
        	len = nums[i] > nums[i-1] ? (len + 1): 1;
        	res = max( len, res );
        }
        return res;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	vector<int> v1 =  {1,3,5,4,7}, v2( 5,2 );
	cout << sol.findLengthOfLCIS(v1) << endl;
	cout << sol.findLengthOfLCIS(v2) << endl;
	return 0;
}