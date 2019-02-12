#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by considering the 3 case that can form a Palidrome
 * case 1: without delete
 * case 2: delete a character at the first half of 's'
 * case 3: delete a character at the second half of 's'
 * 
 * Author: Yangyao, 2019/02/13
 */
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), nd2 = n/2;
        if( n <= 2 ) return true;

        // case 1        
        int indx1 = nEqual( s, nd2-1 );
        if( indx1 == nd2-1 ) return true;
        
        // case 2
        int indx2 = nEqualReversed(s, (n & 1)?nd2:(nd2-1), nd2+1 );
        if( indx2 <= indx1+2 ) return true;

        // case 3
        indx2 = nEqualReversed(s, (n & 1)?(nd2-1):(nd2-2), nd2);
        return indx2 <= indx1 + 1;
    }
    static int nEqual(string &s, int n){
        int i = 0;
        while( i <= n && s[i] == s[s.size()-1-i] ) ++i;
        return i-1;
    }
    static int nEqualReversed(string &s, int n1, int n2){
        while( n1 >= 0 && n2 < s.size() && s[n1] == s[n2] ){ --n1; ++n2; }
        return n1+1;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // some examples for unit-test
    cout << sol.validPalindrome("aba") << endl;
    cout << sol.validPalindrome("abdcba") << endl;
    cout << sol.validPalindrome("abdefcfeba") << endl;
    cout << sol.validPalindrome("abeddba") << endl;

    cout << sol.validPalindrome("abdekcfeba") << endl;
    cout << sol.validPalindrome("areddba") << endl;
    return 0;
}
