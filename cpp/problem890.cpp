// Class: Use array to map char to char
// Description:
//  - Two arrays, one maps char from word to pattern, one from pattern to word.
//  - For each pair of chars ( word[i] and pattern[i] ),
//     check if the permutation is consistent with the previous.
// Creat: Yangyao Chen, 2018/10/26

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(const auto & word: words){
            if( isMatch(word, pattern) ) res.emplace_back( std::move(word) );
        }
        return res;
    }
    bool isMatch( const string &s, const string &p ){
        char perm[26] = {}, invperm[26] = {};
        int is, ip;
        for( int i = 0, n = s.size(); i < n; ++i ){
            is = s[i] - 'a';
            ip = p[i] - 'a';
            if( perm[is] ){
                if( perm[is] != p[i] || invperm[ip] != s[i] ) return false;
            }else{
                if( invperm[ip] ) return false;
                perm[is] = p[i]; invperm[ip] = s[i];
            }
        }
        return true;
    }
};
