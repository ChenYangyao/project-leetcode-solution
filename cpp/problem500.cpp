#include <cctype>
#include <string>
#include <vector>

const int line_ids[26] = {2,3,3,2,1,2,2,
                2,1,2,2,2,3,3,
                1,1,1,1,2,1,
                1,3,1,3,1,3};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for( const auto & word: words ){
            if( is_inline( word ) ){ res.emplace_back( word ); }
        }
        return res;
    }
    bool is_inline( const string & word ){
        int line_id = line_ids[ tolower(word[0]) - 'a' ];
        for( auto c: word ){
            if( line_ids[ tolower(c) - 'a'] != line_id ) return false;
        }
        return true;
    }
};
