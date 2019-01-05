#include <mystd.h>
using namespace std;

/**
 * Solution is trivial: 
 *    two indexes move in opposite direction, swap for each pair of vowels, and stop when
 *    encountering.
 * It is not sure which is the best to implement isVowel(char), hash or simple if/switch?
 */
class Solution {
public:
    string reverseVowels(string s) {
    	if( !s.empty() ){
	     	int b = -1, e = s.size();
	     	while( next(b,e,s) ) swap( s[b], s[e] );
    	}
    	return s;
    }
    static bool next( int &b, int &e, const string &s ){
    	while( ++b < e && !isVowel(s[b]) );
    	while( b < --e && !isVowel(s[e]) );
    	return b < e;
    }
    static bool isVowel( char c ){
    	switch(c){
    		case 'a': case 'e': case 'i': case 'o': case 'u':
    		case 'A': case 'E': case 'I': case 'O': case 'U':
    			return true;
    	}
    	return false;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	cout << sol.reverseVowels("hello") << endl;
	cout << sol.reverseVowels("leetcode") << endl;
	return 0;
}