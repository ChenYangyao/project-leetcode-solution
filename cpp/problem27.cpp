#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * solution by filling the removed element from tail
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
  		int i = 0, j = nums.size();
  		while(true) {
  			while(i < j && nums[i] != val) ++i;
  			if( i == j ) break;
  			while( --j > i && nums[j] == val ) ;
  			if( i == j ) break;
  			nums[i] = nums[j]; 
  		}
  		return i;
    }
};


int main(int argc, char const *argv[]){
	// test case in the Leetcode problem
	vector<int> v1 = {3,2,2,3}, v2 = {0,1,2,2,3,0,4,2};
	Solution sol;
	auto rem = sol.removeElement( v1, 3 );
	cout << rem << endl;
	MYFILE::print_range( v1.data(), v1.data() + rem ) << endl;

	rem = sol.removeElement( v2, 2 );
	cout << rem << endl;
	MYFILE::print_range( v2.data(), v2.data() + rem ) << endl;
	return 0;
}