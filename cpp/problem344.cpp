#include <string>

class Solution {
public:
    string reverseString(string s) {
        return string( s.crbegin(), s.crend() );
    }
};
