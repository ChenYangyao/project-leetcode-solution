#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * method that mostly saves space and time
 * 
 * Starting from target = strs[0][1...n[, where n = strs[0].length,
 * we compare target with other strings in strs, and shrink target
 * gradually to the common prefix.
 * 
 * Note that there is no string copy and generation (until return of 
 * the called method).
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty() ) return "";
        auto &t = strs[0]; 
        size_t n = t.size();
        for(size_t i=1; i<strs.size(); ++i){
            findMismatch( t, strs[i], n );
            if( n == 0 ) break;
        }
        return t.substr(0, n);
    }
    void findMismatch(string &t, string &s, size_t &n){
        size_t maxIdx = min( n, s.size() ), j = 0;
        while( j < maxIdx && s[j] == t[j] ) ++j;
        n = j;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    
    // test cases in Leetcode Problem
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix( strs ) << endl;
    strs = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix( strs ) << endl;

    return 0;
}