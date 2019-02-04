#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * solution using a sliding window, counting recorded by arrays
 * 
 * Here in the implementation, cnt_s[26] and cnt_p[26] are used to record
 * the counting of characters in string s and p, respectively.
 * At each step, the sliding window of size = p.size() proceeds forward, 
 * cnt_s and cnt_p are updated and compared to find the anagram substring.
 * 
 * We use a trick to speed up the comparison of cnt_s and cnt_p. At each
 * step, we record the index where cnt_s and cnt_p mismatch. Later comparison
 * begins at this mismatching index. Since at each step only the counting 
 * for 2 of 26 charaters are updated, previous mismtach is very possible to 
 * mismatch again. 
 * 
 * This method should be ideal for very long string p.
 * Time: O(s.length); space: O(1), mainly from cnt_s and cnt_p.
 * Author: Yangyao, 2019/02/04
 */ 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if( s.size() < p.size() ) return ans;

        short cnt_s[NCHAR] = {}, cnt_p[NCHAR] = {};
        int indx = 0, m = p.size();
        init_cnt(s, m, cnt_s);
        init_cnt(p, m, cnt_p);
        do{
            if( compare_cnt( cnt_s, cnt_p, indx ) )
                ans.push_back( m - p.size() );
        }while( proceed_cnt( s, p.size(), m, cnt_s ) );
        return ans;
    }
    void init_cnt(string &s, int n, short *cnt){
        for(int i=0; i<n; ++i) ++cnt[ s[i] - 'a' ];
    }
    /**
     * proceed sliding window by one step
     */
    bool proceed_cnt(string &s, int n, int &m, short *cnt){
        if( m == s.size() ) return false;
        --cnt[ s[ m - n ] - 'a' ];
        ++cnt[ s[ m++ ] - 'a' ];
        return true;
    }
    /**
     * Trick here for comparing cnt_s and cnt_p is to record a 
     * mismatch index 'int &indx'.
     */ 
    bool compare_cnt(short *cnt_s, short *cnt_p, int &indx){
        for(int i=indx; i<NCHAR; ++i){
            if( cnt_s[i] != cnt_p[i] ){
                indx = i; return false;
            }
        }
        for(int i=0; i<indx; ++i){
            if( cnt_s[i] != cnt_p[i] ){
                indx = i; return false;
            }
        }
        return true;
    }
    static const int NCHAR = 26;
};

/**
 * solution also using a sliding window, but counting of substring in s
 * is recorded by hash-maps. Counting of p still uses array for performance.
 * 
 * This method should be better for short string p.
 * Time: O(s.length); space: O(1), mainly from cnt_s and cnt_p.
 */ 
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if( s.size() < p.size() ) return ans;

        short cnt_p[NCHAR] = {};
        for(auto c: p) ++cnt_p[ c - 'a' ];

        int m = p.size();        
        unordered_map<char, short> cnt_s;
        for(int i=0; i<m; ++i) ++cnt_s[ s[i] ];

        do{
            if( compare_cnt( cnt_s, cnt_p ) )
                ans.push_back( m - p.size() );
        }while( proceed_cnt( s, p.size(), m, cnt_s ) );
        return ans;
    }
    /**
     * proceed sliding window by one step
     */
    bool proceed_cnt( string &s, int n, int &m, unordered_map<char, short> &cnt_s ){
        if( m == s.size() ) return false;
        auto it = cnt_s.find( s[ m - n ] );
        if( it->second == 1 ) cnt_s.erase( it );
        else --it->second;
        ++cnt_s[ s[m++] ];
        return true;
    }
    bool compare_cnt( unordered_map<char, short> &cnt_s, short *cnt_p ){
        for(auto &it: cnt_s)
            if( cnt_p[ it.first - 'a' ] != it.second ) return false;
        return true;
    }
    static const int NCHAR = 26;
};


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // cases in Leetcode Problem
    string s = "cbaebabacd", p = "abc";
    MYFILE::print_range( sol.findAnagrams( s, p ) ) << endl;
    MYFILE::print_range( sol2.findAnagrams( s, p ) ) << endl;

    s = "abab", p = "ab";
    MYFILE::print_range( sol.findAnagrams( s, p ) ) << endl;
    MYFILE::print_range( sol2.findAnagrams( s, p ) ) << endl;
    return 0;
}
