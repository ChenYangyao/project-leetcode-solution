class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = t.back();
        for( int i = 0, n = s.size(); i < n; ++i ){
            res ^= s[i] ^ t[i];
        }
        return char(res);
    }
};
