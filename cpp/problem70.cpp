#include "mystd.h"
using namespace std;

/**
 * since N[n] = N[n-1] + N[n-2]
 * we know this is a Fabnacci sequence.
 *
 * Simplest way to find N[n] is to follow the definition of N[n].
 * This takes Theta(n) time, and Theta(1) space
 */
class Solution {
public:
    int climbStairs(int n) {
		if( n == 1 ) return 1;
		if( n == 2 ) return 2;
		int prev = 1, curr = 2, post;
		for (int i = 3; i <= n; ++i){
			post = prev + curr;
			prev = curr;
			curr = post;
		}
		return curr;
    }
};

/**
 * or, just use the mathematical result for N[n]
 * this takes Theta(1) time, and space
 */
class Solution2 {
public:
    int climbStairs(int n) {
		++n;
		double sqr5 = sqrt(5);
		return (pow((1+sqr5)/2,n) - pow((1-sqr5)/2, n))/sqr5 + 1.0e-10;
    }
};


int main(int argc, char const *argv[])
{
	Solution sol;
	Solution2 sol2;
	cout << sol.climbStairs( 3 ) << endl;
	cout << sol2.climbStairs( 3 ) << endl;
	return 0;
}