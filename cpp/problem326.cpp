#include <mystd.h>
using namespace std;

/**
 * direct look-up by hash set
 */
const unordered_set<int> st({
	1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 
	531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 
	1162261467});
class Solution {
public:
    bool isPowerOfThree(int n) {
        return st.count( n );
    }
};

/**
 * since 3 is a Primer, so the following method is correct
 * Reference: Leetcode User Solution
 */
const int maxPowerOf3 = pow(3, int( log(INT_MAX) / log(3) )  +1.0e-10 );
class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(maxPowerOf3 % n);
    }
};

/**
 * this is somehow tricky, becuase it envolves float-arithmetic, not necessarily correct
 * Reference: Leetcode Discussion
 */
class Solution3 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && int( log(n)/log(3) ) == log(n)/log(3);
    }
};

int main(int argc, char const *argv[]){
	Solution sol;
	Solution2 sol2;
	Solution3 sol3;

	for(auto i: {27,0,9,45}){
		cout << "i: " << i << ", " << sol.isPowerOfThree( i ) << endl;
		cout << "i: " << i << ", " << sol2.isPowerOfThree( i ) << endl;
		cout << "i: " << i << ", " << sol3.isPowerOfThree( i ) << endl;
	}
	
	return 0;
}