#include <mystd.h>
using namespace std;

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


int main(int argc, char const *argv[]){
	Solution sol;
	cout << sol.isPalindrome( 121 ) << endl;
	cout << sol.isPalindrome( -121 ) << endl;
	cout << sol.isPalindrome( 10 ) << endl;
	return 0;
}
