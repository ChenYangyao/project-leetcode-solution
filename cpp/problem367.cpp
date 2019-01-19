#include <mystd.h>
using namespace std;

/**
 * solution by bisection searching
 * Author: Yangyao, 2018/01/16
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
		long l = 0, r = num + 1;
		do{
			long c = (l+r)/2, c2dn = c*c - num;
			if( c2dn == 0 ) return true;
			else if( c2dn < 0 ) l = c;
			else r = c;
		}while( r - l > 1 );
		return false;
    }
};

/**
 * same as bisection, but avoid using longer interger type
 *
 * The key is to find the maximal square root 'maxSqrt' of 
 * any possible int number. If input 'num' exceeds the square 
 * of 'maxSqrt', we directly reject it. Subsequent iterations 
 * will keep all values in the range [0, INT_MAX] so there 
 * is no need for a longer integer type.
 *
 * Author: Yangyao, 2018/01/16
 */
class Solution2{
public:
	bool isPerfectSquare(int num){
		if( num > maxSqrt * maxSqrt ) return false;
		int l = 0, r = maxSqrt + 1;
		do{
			int c = (l + r)/2, c2dn = c*c - num;
			if( c2dn == 0 ) return true;
			else if( c2dn < 0 ) l = c;
			else r = c;
		}while( r - l > 1 );
		return false;
	}
protected:
	static const int maxSqrt = 46340;
};

/**
 * newton algorithm
 * Newton's algorithm for root-searching is typically used in float-point 
 * computation. However I have found that it is also valid in this question 
 * without using any float-point number.
 * The initial point `x1` in the code is chosen arbitrary.
 *
 * Let the true square root `x = sqrt(num)` (real number), and the currect 
 * position in newton algorithm to be `x0` (integer number, see the code for 
 * how to iterate).  The key points, for proving this method is correct, are 
 * (I skip the detail proof):
 * (1) When `|x - x0|>=2`, the newton searching point in the next iteration 
 * will always be changing (not frozen in a interger point).
 * (2) When `|x - x0|<2`, the newton searching point in the next iteration 
 * will gose towards `x` by exactly `1`。So if `x` is a interger, we will find 
 * the answer, otherwise `x` must not be a integer and we return false.
 *
 * Author: Yangyao, 2018/01/16
 */
class Solution3{
public:
	bool isPerfectSquare(int num){
		long x0, x1 = num/2 + 1;
		do{
			x0 = x1;
			x1 = (num + x0 * x0)/(2 * x0);
			if( x1 * x1 == num ) return true;
		}while( abs(x1-x0) > 1 );
		return false;
	}
protected:
};

int main(int argc, char const *argv[]){
	Solution sol;
	Solution2 sol2;
	Solution3 sol3;

	for (int i = 1; i < 99; ++i){
		cout << i << ": " << sol.isPerfectSquare(i) 
			<< ", " << sol2.isPerfectSquare(i)
			<< ", " << sol3.isPerfectSquare(i) <<  endl;
	}
	return 0;
}