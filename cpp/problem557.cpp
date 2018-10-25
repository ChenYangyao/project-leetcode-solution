#include <mystd.h>
using namespace MYSTD;


class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        ostringstream os;
        string temps;

        is >> temps;
        os << string( temps.crbegin(), temps.crend() );
        while( is >> temps ){
            os << ' ' << string( temps.crbegin(), temps.crend() );
        }
        return os.str();
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.reverseWords( "Let's take LeetCode contest" ) << endl;
    return 0;
}
