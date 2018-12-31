#include <mystd.h>
using namespace std;

/**
 * similar to problem 693 (identifying whether all bits of a integer are 1)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
  		return n > 0 && !( n & (n-1) );
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	// cases in Leetcode problem
	cout << sol.isPowerOfTwo(1) << endl;
	cout << sol.isPowerOfTwo(16) << endl;
	cout << sol.isPowerOfTwo(218) << endl;
	return 0;
}