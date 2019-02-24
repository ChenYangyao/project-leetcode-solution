#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * Only in the following cases can A be swapped to match B:
 * (1) A and B differ in exactly 2 characters, and can be swapped to match.
 * (2) A and B is identical, and A has at least one character appearing  
 *      twice or more.
 * 
 * Author: Chen Yangyao, 2019/02/24
 */ 
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n = A.size();
        if( n < 2 || B.size() != n ) return false;
        char d1 = 0, d2 = 0;
        for(int i=0; i<n; ++i){
            if( A[i] != B[i] ){
                if( !d1 ){ d1 = A[i]; d2 = B[i]; }
                else{ 
                    return B[i] == d1 && A[i]==d2 && 
                        equal( A.begin()+i+1, A.end(), B.begin()+i+1 );
                }
            }
        }
        if( d1 ) return false;
        std::unordered_set<char> cnt;
        for(auto c: A){
            if( ! cnt.emplace(c).second ) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]){

    Solution sol;
    // cases in Leetcode Problem
    cout << sol.buddyStrings("ab","ba") << endl;
    cout << sol.buddyStrings("ab","ab") << endl;
    cout << sol.buddyStrings("aa","aa") << endl;
    cout << sol.buddyStrings("aaaaaabc","aaaaaacb") << endl;
    cout << sol.buddyStrings("","aa") << endl;

    // case in Leetcode Judgement System
    cout << sol.buddyStrings("abcd","badc") << endl;

    return 0;
}