class Solution {
public:
    int romanToInt(string s) {
        int res = 0, ct = 0, n = s.size()-1;

        while( n >= 0 && s[n] == 'I' ){ ++ct; --n; }
        res += ct;

        int base, diff; char c;
        while( n >= 0 ) {
            switch(s[n--]){
                case 'V': base = 5; diff = -1; c = 'I'; break;
                case 'X': base = 10; diff = -1; c = 'I'; break;
                case 'L': base = 50; diff = -10; c = 'X'; break;
                case 'C': base = 100; diff = -10; c = 'X'; break;
                case 'D': base = 500; diff = -100; c = 'C'; break;
                case 'M': base = 1000; diff = -100; c = 'C'; break;
            }
            if( n >= 0 && s[n] == c ){
                res += base + diff; --n;
            }else res += base;
        }

        return res;
    }
};
