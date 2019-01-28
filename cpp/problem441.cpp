#include <mystd.h>
using namespace MYSTD;
using namespace std;

// By using mathematical formula for staircase sum(1...k) = k(k+1)/2,
// solution is simply a root-findting problem.
class Solution {
public:
    int arrangeCoins(int n) {
        long b = -1, e = 65536, c, dy;
        if( n >= e*(e-1)/2 ) return e-1;
        do{
            c = (b + e)/2; dy = c*(c+1)/2 - n;
            if( dy > 0 ) e = c;
            else if( dy < 0 ) b = c;
            else return c;
        }while( e > b+1 );
        return b;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    // cases in Leetcode Problem
    cout << sol.arrangeCoins(5) << endl;
    cout << sol.arrangeCoins(8) << endl;
    // other extreme cases
    cout << sol.arrangeCoins(0) << endl;
    cout << sol.arrangeCoins(1) << endl;
    return 0;
}