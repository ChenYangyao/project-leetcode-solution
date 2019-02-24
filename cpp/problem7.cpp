#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * reverse x by extracting its least-significant bits gradually, and push
 * them into the result.
 * 
 * Author: Chen Yangyao, 2019/02/24
 */ 
class Solution {
public:
    int reverse(int x) {
        if( x == INT_MIN ) return 0;
        
        bool is_neg = x < 0; 
        x = abs(x); int rx = 0;
        do{
            if( rx > 214748364 ) return 0;
            rx = rx*10 + x%10;
            if( rx < 0 ) return 0;
        }while( x/=10 );
        return is_neg?-rx:rx;
    }
};

int main(int argc, char const *argv[]){

    Solution sol;
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(120) << endl;

    return 0;
}