class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n>>1);
        return !( (x+1) & x );
    }
};
