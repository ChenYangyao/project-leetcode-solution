#include <mystd.h>
using namespace std;

/**
 * the key is that a number is power of 4 iff
 * 1. it is power of 2
 * 2. the set bit can only appear at ...01010101
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
    	return isPowerOfTwo(num) && (num & 0x55555555 );
    }
    bool isPowerOfTwo(int num) {
    	return (num > 0) && !( num & (num-1) );
    }
};

int main(int argc, char const *argv[]){
	Solution sol;

	// cases in Leetcode Problem
	//	 with some other cases
	for(auto i: {16,5,4,8,64,63}){
		cout << i << ": " << sol.isPowerOfFour(i) << endl;
	}
	return 0;
}