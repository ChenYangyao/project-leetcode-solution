#include <mystd.h>
using namespace std;

/**
 * solution by bisect searching
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


int main(int argc, char const *argv[]){
	Solution sol;
	for (int i = 1; i < 99; ++i){
		cout << i << ": " << sol.isPerfectSquare(i) << endl;
	}
	return 0;
}