#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * follow the definition of perfect number
 * Here we consider all numbers below sqrt(num) which are possible divisors.
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if( num <= 1 ) return false;
        
        int sumOfDivisor = 0;
        int t = sqrt(num + 0.9);

        // For perfect square number, the square root should be added only once
        if( t*t == num ){ sumOfDivisor += t; --t; } 
        // 1 should be added, while num itself should not.
        sumOfDivisor += 1;                           
        // other divisors
        for(int i=2; i<=t; ++i){
            if( num%i == 0 ){
                sumOfDivisor += i + num/i;
            } 
        }
        return sumOfDivisor == num;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    // test case in Leetcode Problem
    cout << sol.checkPerfectNumber(28) << endl;
    // Other extreme case
    cout << sol.checkPerfectNumber(0) << endl;
    cout << sol.checkPerfectNumber(1) << endl;
    cout << sol.checkPerfectNumber(25) << endl;
    return 0;
}
