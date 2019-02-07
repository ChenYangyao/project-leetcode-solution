#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * solution by following the definition of isomorphic map
 * An isomorhic map is a one-to-one map between characters, so
 * we scan the string s and t, record the map between characters
 * and exclude the case where one character in s is mapped to multiple
 * images in t or multiple characters in s are mapped to a common
 * image in t.
 * 
 * Time: Theta(n), space: Theta(min(n, 255))
 * 
 * Author: Yangyao, 2019/02/02
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if( t.size() != n ) return false;

        unordered_map<char, char> ccmap;        // map of characters from s to t
        for(int i=0; i<n; ++i){
            auto it = ccmap.find( s[i] );
            if( it != ccmap.end() ){            // exclude one-to-multiple map
                if( it->second != t[i] ) return false;
            }else ccmap.emplace( s[i], t[i] );
        }
        return isDuplicated( ccmap );           // exclude multiple-to-one map
    }
    bool isDuplicated(unordered_map<char, char> &ccmap){
        unordered_set<char> cset;
        for(auto &pair: ccmap){
            if( cset.find( pair.second ) != cset.end() ) return false;
            cset.emplace( pair.second );
        }
        return true;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode solution
    cout << sol.isIsomorphic( "egg", "add" ) << endl;
    cout << sol.isIsomorphic( "foo", "bar" ) << endl;
    cout << sol.isIsomorphic( "paper", "title" ) << endl;
    // case in Leetcode judgement system
    cout << sol.isIsomorphic( "ab", "aa" ) << endl;
    return 0;
}
