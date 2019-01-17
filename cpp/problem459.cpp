#include <mystd.h>
using namespace std;


/**
 * solution by trying each sub-string (taken from the beginning of input s)
 * In the worst case, e.g., s = "aaaaaaaaaaab", at each trying by checkAllPieces(),
 * the comparison lasts until the last character 'b'.
 *
 * But only when s.size() % n == 0 we do this comparison, so the total amount of
 * TIME spent on the worst case is far less than n^2, but still greater than n.
 *
 * The merit of this method is that it takes no extra memory.
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1, sz = s.size()/2; i <= sz; ++i){
        	if( checkAllPieces(s, i) ) return true;
        }
        return false;
    }
    /**
     * check whether s[1:n) is the repearted pattern
     * This is done by compare s[1:n) with s[n,2n), s[2n, 3n), ... .
     */
    bool checkAllPieces(const string &s, int n){
    	if( s.size() % n != 0 ) return false;
    	for (int i=n; i != s.size(); i+=n){
    		if( !checkOnePiece(s, n, i) ) return false;
    	}
    	return true;
    }
    /**
     * check whether s[1:n) == s[beg, beg+n)
     */
    bool checkOnePiece(const string &s, int n, int beg){
    	return equal( s.c_str(), s.c_str()+n, s.c_str()+beg );
    }
};

/**
 * a simple solution extracted from Leetcode User solution
 *
 * The time cost depends on the implementation of s. It KMP algorithm
 * (or KMP-like algorithm) is used, the time will be O(n), but cost
 * extra O(n) space.
 */
class Solution2 {
public:
    bool repeatedSubstringPattern(string s){
        return (s+s).find(s,1) != s.size();
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
    Solution2 sol2;
    // cases in Leetcode Problem
	for(string s: {"abab","aba","abcabcabcabc"}){
		cout << sol.repeatedSubstringPattern( s ) << sol2.repeatedSubstringPattern( s ) << endl;
	}
	return 0;
}