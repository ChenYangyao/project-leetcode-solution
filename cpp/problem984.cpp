#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * Let's assume, e.g., A > B, we gradually run out of A and B.
 * At each step, we append result string with 2 'a's and 1 'b',
 * so that A decrease faster than B. If at some time A == B, it
 * is easy to fill the remaining 'a's and 'b's pair by pair such
 * as 'ababab...'.
 * 
 * Author: Yangyao, 2019/02/17
 */ 
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        return A > B?strWithout3a3b(A,B,'a','b'):strWithout3a3b(B,A,'b','a');
    }
    string strWithout3a3b(int A, int B, char a, char b){
        string s(A + B, a); int i = 0;      // Memory is pre-allocated and all filled with 'a's.
        while( A > B ){
            if( B > 0 ){ i += 2; A -= 2; s[i++] = b; --B; }
            else{ i += A; A = 0; }          // If B is run out before A == B, direct fill s with 'a's.
        }
        --i;
        while( A-- > 0 ){ s[i+=2] = b; }    // fill 'ab' pair by pair
        return s; 
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.strWithout3a3b(1,2) << endl;
    cout << sol.strWithout3a3b(4,1) << endl;

    cout << sol.strWithout3a3b(6,2) << endl;
    cout << sol.strWithout3a3b(6,3) << endl;
    cout << sol.strWithout3a3b(6,4) << endl;
    cout << sol.strWithout3a3b(5,2) << endl;
    return 0;
}