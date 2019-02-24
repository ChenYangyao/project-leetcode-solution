#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * Let, for example, 'ABC' = (1,2,3), then for a excel notation
 * n = (...,n3,n2,n1) it is easy to prove that the corresponding
 * digital representation is n = ... + n3*26*26 + n2*26 + n1,
 * where each ni takes value between 1 and 26.
 *  
 * So, when n != 0, if n % 26 = 0, we can say n1 must be 26, other-
 * wise n1 must be n %26. This gives the solution below.
 * 
 * Author: Yangyao, 2019/02/24
 */
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int temp;
        do{
            temp = n%26;
            if( temp ){
                ans += i2Char(temp);
            }else{
                ans += i2Char(26);
                n -= 26;
            }
        }while( n /= 26 );
        reverse( ans.begin(), ans.end() );
        return ans;
    }
    static char i2Char(int i) {
        return 'A' + i - 1;
    }
};

/**
 * follow the notation in the above solution,
 * since n = ... + n3*26*26 + n2*26 + n1,
 * we know when n != 0, n-1 % 26 must be equal to n1-1.
 * This gives the solution2 below.
 * 
 * Reference: Leetcode User Solution
 * Author: Yangyao, 2019/02/24
 */ 
class Solution2 {
public:
    string convertToTitle(int n) {
        string ans;
        do{
            n -= 1;
            ans += 'A' + (n % 26);
        }while( n /= 26 );
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    // examples in Leetcode Problem
    cout << sol.convertToTitle(1) << endl;
    cout << sol2.convertToTitle(1) << endl;
    cout << sol.convertToTitle(28) << endl;
    cout << sol2.convertToTitle(28) << endl;
    cout << sol.convertToTitle(701) << endl;
    cout << sol2.convertToTitle(701) << endl;
    return 0;
}