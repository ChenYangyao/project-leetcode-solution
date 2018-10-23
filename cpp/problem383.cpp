class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> nAppears;
        for(auto c: magazine) ++nAppears[c];
        for(auto c: ransomNote)
            if( -- nAppears[c] < 0 ) return false;
        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int nAppears[26] = {0};
        for(auto c: magazine) ++nAppears[c-'a'];
        for(auto c: ransomNote)
            if( --nAppears[c-'a'] < 0 ) return false;
        return true;
    }
};
