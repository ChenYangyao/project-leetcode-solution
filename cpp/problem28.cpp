#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * KMP algorithm
 * See any text book of algorithm/data structure for the detail.
 * 
 * Space: linear with pattern string ('needle' here).
 * Time: Linear with pattern.length + target.length.
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if( needle.empty() ) return 0;      // follow the requirement of this question

        vector<int> patMoves(n);
        getPatMoves(needle, patMoves);      // compute move array of pattern string
        
        int i = 0, j = 0;
        while( i < m && j < n ){            // implementation of KMP
            if( haystack[i] == needle[j] ){ ++i; ++j; }
            else if( j == 0 ) ++i;
            else j = patMoves[j-1];
        }
        return j==n ? (i-n): -1;
    }
    static void getPatMoves(string &pat, vector<int> &patMoves){
        patMoves[0] = 0;
        for(int i=1, n=pat.size(); i<n; ++i){
            int j=i;
            do{
                j=patMoves[j-1];
                if( pat[j] == pat[i] ){ patMoves[i] = j+1; break; }
            }while(j);
        }
    }  
};

int main(int argc, char const *argv[]){
    string pat = "aaabaa"; vector<int> patMoves(pat.size());  
    Solution::getPatMoves(pat,patMoves);
    MYFILE::print_range(patMoves) << endl;

    // cases in Leetcode Problem
    Solution sol;
    cout << sol.strStr("hello", "ll") << endl;
    cout << sol.strStr("aaaaa", "bba") << endl;
    return 0;
}