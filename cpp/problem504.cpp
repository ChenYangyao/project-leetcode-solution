#include "mystd.h"
using namespace std;

/**
 * solution by mod 7
 */
class Solution {
public:
    string convertToBase7(int num) {
        bool is_negative = num < 0? true:false;

        num = abs(num);
        string res = num == 0?"0":"";
        while( num ){
            res += char( num % 7 + '0' );
            num = num / 7;
        }
        if(is_negative) res += "-";
        reverse(res.begin(), res.end());
        return res;
    }
};



int main(int argc, char const *argv[]){
    // two test examples in Leetcode Problem
    int num1 = 100, num2 = -7;
    Solution sol;

    cout << sol.convertToBase7( num1 ) << endl;
    cout << sol.convertToBase7( num2 ) << endl;
    return 0;
}
