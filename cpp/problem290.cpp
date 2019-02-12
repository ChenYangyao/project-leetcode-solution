#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by checking the definition of a bijection
 * (1) it is a funtion/mapping
 * (2) it is full
 * (3) it is a injection
 */ 
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // determine if it is a function (i.e., whether one-to-multiple happens)
        std::unordered_map<string, char> str2pat;
        int i = 0, j = 0, k = 0;
        while( toSpace( str, j ) ){
            if( k == pattern.size() ) return false;
            auto substr = str.substr( i, j - i );
            auto it = str2pat.find( substr );
            if( it != str2pat.end() ){
                if( it->second != pattern[k] ) return false;
            }else str2pat[ substr ] = pattern[k];
            i = ++j;
            ++k;
        }
        // determine if it is a full mapping
        if( k < pattern.size() ) return false;

        // determine if it is injective (i.e., whether multiple-to-one happens)
        std::unordered_set<char> pats;
        for(const auto &i: str2pat){
            if( pats.find( i.second ) != pats.end() ) return false;
            pats.emplace(i.second);
        }
        return true;
    }
    bool toSpace(string &str, int &j){
        if( j >= str.size() ) return false;
        while( j < str.size() && str[j] != ' ' ) ++j;
        return true;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem
    cout << sol.wordPattern( "abba", "dog cat cat dog" ) << endl;
    cout << sol.wordPattern( "abba", "dog cat cat fish" ) << endl;
    cout << sol.wordPattern( "aaaa", "dog cat cat fish" ) << endl;
    cout << sol.wordPattern( "abba", "dog dog dog fish" ) << endl;

    // a special case where the mapping is not full
    cout << sol.wordPattern( "abbaa", "dog cat cat dog" ) << endl;
    // a special case where it is not a mapping
    cout << sol.wordPattern( "", "dog cat cat dog" ) << endl;
    
    return 0;
}
