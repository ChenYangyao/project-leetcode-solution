#include "mystd.h"
using namespace MYSTD;


/**
 * solution by counting each appeared character
 * Description:
 *  - time complexity: O(2n), n is the length of string.
 *  - constant space cost.
 */
class Solution {
public:
    int firstUniqChar(string s) {
        if( s.empty() ) return -1;
        int count_char[26] = {0};
        for(auto c: s) ++count_char[ c - 'a' ];
        for(int i = 0, n = s.size(); i < n; ++i)
            if( count_char[ s[i] - 'a' ] == 1 )
                return i;
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    string s1 = "asdahtrkafa";
    Solution sol;
    cout << sol.firstUniqChar( s1 ) << endl;
    return 0;
}
