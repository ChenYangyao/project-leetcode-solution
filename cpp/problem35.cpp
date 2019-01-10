#include <mystd.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int b = 0, e = nums.size(), c;
		while( b != e ){
			c = b + (e-b)/2;
			if( target == nums[c] ){ b = c; break; }
			else if( target < nums[c] ) e = c;
			else b = c+1;
		}
		return b;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	vector<int> nums;

	nums.assign( {1,3,5,6} );
	cout << sol.searchInsert( nums,5 ) << endl;

	cout << sol.searchInsert( nums,2 ) << endl;

	nums.assign( {1,3,5,6} );
	cout << sol.searchInsert( nums,7 ) << endl;

	nums.assign( {1,3,5,6} );
	cout << sol.searchInsert( nums,0 ) << endl;
	return 0;
}