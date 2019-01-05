#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * from least-significant digit, try to plus 1, and repeat
 * for higher digit when exceeding 9.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
  		int i = digits.size() - 1;
  		while( i >= 0 ){
  			if( digits[i] == 9 ){
  				digits[i--] = 0;
  			}else{
  				++digits[i]; return digits;
  			}
  		}
  		digits.insert(digits.begin() ,1);
  		return digits;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// cases from Leetcode problem
	vector<int> v = {1,2,3};
	MYFILE::print_range( sol.plusOne(v) ) << endl;
	v.assign({4,3,2,1});
	MYFILE::print_range( sol.plusOne(v) ) << endl;
	// some extreme cases
	v.assign({7,9,9,9});
	MYFILE::print_range( sol.plusOne(v) ) << endl;
	v.assign({9,9,9,9});
	MYFILE::print_range( sol.plusOne(v) ) << endl;
	return 0;
}