#include "mystd.h"
using namespace std;

/**
 * why this simple question has so low pass-rate?
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        auto b = s.begin(), e = s.end();
        while( b < e ){
            reverse( b, min(b+k, e) );
            b += k+k;
        }
        return s;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    auto s = sol.reverseStr("abcdefg",2);
    cout << s << endl;
    return 0;
}
