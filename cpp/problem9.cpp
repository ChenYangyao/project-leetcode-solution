#include <mystd.h>
using namespace std;

/**
 * method by taking extra memory for digits
 */
class Solution {
public:
    bool isPalindrome(int x) {
    	if( x < 0 ) return false;
		
        int ndigits = 0;
        while( x ){
        	digits[ ndigits++ ] = x % 10;
        	x /= 10;
        }

        int i = 0; --ndigits;
        while( i < ndigits ){
        	if( digits[ i++ ] != digits[ ndigits-- ] ) 
        		return false;
        }    
        return true;
    }
	char digits[10];
};

/**
 * method by getting the digits ordered and reversed, and compare them
 * this seems stupid...
 */
class Solution2 {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;

        int n, pow10;
        lastDigit( x, n, pow10 );
        n >>= 1;
        
        int _x = x;
        for (int i = 0; i <= n; ++i){
            if( x / pow10 != _x % 10 ) return false;
            x %= pow10; pow10 /= 10; 
            _x /= 10;
        }
        return true;
    }
    void lastDigit( int x, int &n, int &pow10 ){
        n = 0, pow10 = 1;
        while( x /= 10 ){
            ++n; pow10 *= 10;
        }
    }
};

/**
 * an amazing solution
 * Reference: Leetcode user sample
 */
class Solution3 {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;
        int _x = x;
        int n = 0;
        while( x ){
            n = n*10 + x%10;
            x /= 10;
        }
        return _x == n;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    // cases, from Leetcode problem, and myself
    for(auto i: {121,-121,10,1,0}){
	   cout << sol.isPalindrome( i ) 
        << " and " << sol2.isPalindrome( i ) 
        << " and " << sol3.isPalindrome( i ) << endl; 
    }
	return 0;
}
