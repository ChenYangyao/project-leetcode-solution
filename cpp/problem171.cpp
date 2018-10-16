class Solution {
public:
    int titleToNumber(string s) {
        int colid = 0, base = 1;
        for(auto it = s.crbegin(); it != s.crend(); ++it){
            colid += (*it - 'A' + 1)*base;
            base *= 26;
        }
        return colid;
    }
};
