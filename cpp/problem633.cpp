#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * try every possible squared number i*i below c, determine whether 
 * the complement = c - i*i is a perfect squared.
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0, rem;
        while( (rem=c- i*i) > 0 ){
            if( isPerfectSquare(rem) ) return true;
            ++i;
        }
        return i*i == c;
    }
protected:
    /**
     * see problem 367: Valid Perfect Square
     * Do not use float point calculation for safety.
     */ 
	bool isPerfectSquare(long num){
		long x0, x1 = num/2 + 1;
		do{
			x0 = x1;
			x1 = (num + x0 * x0)/(2 * x0);
			if( x1 * x1 == num ) return true;
		}while( abs(x1-x0) > 1 );
		return false;
	}
};



/**
 * similar to problem 167: Two Sum II - Input Array is Sorted
 * But here it is the sum of two squared number.
 * 
 * Reference: Leetcode User Solution
 */
class Solution2 {
public:
    bool judgeSquareSum(int c) {
        long i = 0, j = sqrt(c + 0.5), k;
        while( i <= j ){
            k = i*i + j*j;
            if( k < c ) ++i;
            else if( k > c ) --j;
            else return true;
        }
        return false;
    }
};



int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    // extreme cases
    cout << sol.judgeSquareSum( 0 ) << sol2.judgeSquareSum( 0 ) << endl;
    cout << sol.judgeSquareSum( 1 ) << sol2.judgeSquareSum( 1 ) << endl;
    // cases in Leetcode Problem
    cout << sol.judgeSquareSum( 3 ) << sol2.judgeSquareSum( 3 ) << endl;
    cout << sol.judgeSquareSum( 5 ) << sol2.judgeSquareSum( 5 ) << endl;

    return 0;
}