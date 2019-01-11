#include <mystd.h>
using namespace std;

/**
 * solution by reversely formatting the input string
 */
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
    	string res; int n = 0;
    	for( auto it = S.rbegin(); it != S.rend(); ++it ){
    		if( *it != '-' ){
    			res += toupper(*it);
    			if( ++n == K ){
    				res += '-'; 
    				n = 0;
    			}
    		}
    	}
    	if( res.back() == '-' ) res.pop_back();
  		reverse( res.begin(), res.end() );
  		return res;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// test case in Leetcode Solution
	cout << sol.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
	cout << sol.licenseKeyFormatting( "2-5g-3-J", 2) << endl;
	return 0;
}