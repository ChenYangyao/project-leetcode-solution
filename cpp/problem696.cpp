class Solution {
public:
    int countBinarySubstrings(string s) {
        int size = s.size(), res = 0;
        int id1 = 0, id2 = countConsective(s,0), len1 = id2, len2;
        while( id2 < size ){
            len2 = countConsective(s,id2);
            res += min( len1, len2 );
            id1 = id2; id2 += len2;
            len1 = len2;
        }
        return res;
    }
    int countConsective(const string &s, int id){
        int count = 1;
        for (int i = id+1, n = s.size(); i < n; ++i){
            if( s[i] == s[id] ) count += 1;
            else break;
        }
        return count;
    }
};
