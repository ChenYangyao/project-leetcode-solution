#include <mystd.h>
using namespace MYSTD;
using namespace std;

/** 
 * [1, 9] contains 9 bits,
 * [10, 99] contains 90 bits,
 * [100, 999] contains 900 bits ...
 * follow this rule, it is easy to directly calculate the bit
 * corresponds to the input.
 */
class Solution {
public:
    int findNthDigit(int n) {
        long base = 1, ndigit = 1;
        while( n > base * 9 * ndigit ){
            n -= base*9*ndigit; base *= 10; ndigit += 1;
        }
        return ithLeftBit( base+(n-1)/ndigit, ndigit-(n-1)%ndigit);
    }
    int ithLeftBit(int n, int i){
        for(int j=1; j<i; ++j){
            n /= 10;
        }
        return n%10;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.findNthDigit(3) << endl;
    cout << sol.findNthDigit(11) << endl;

    return 0;
}