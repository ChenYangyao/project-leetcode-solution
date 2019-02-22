#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * similar to problem 367 where the task is to identify whether
 * x is a perfect square number.
 */ 
class Solution {
public:
    int mySqrt(int x) {
		if( x > maxSqrt * maxSqrt ) return maxSqrt;
		int l = 0, r = maxSqrt + 1;
		do{
			int c = (l + r)/2, c2dn = c*c - x;
			if( c2dn == 0 ) return c;
			else if( c2dn < 0 ) l = c;
			else r = c;
		}while( r - l > 1 );
		return l;
    }
protected:
	static const int maxSqrt = 46340;
};

int main(int argc, char const *argv[]){
    Solution sol;
    // cases with small integers as input
    for(int i=0; i<99; ++i){
        cout << i << ' ' << sol.mySqrt(i) << endl;
    }
    return 0;
}