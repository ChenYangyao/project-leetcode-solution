#include <mystd.h>
using namespace  MYSTD;
using namespace std;
static int pick;
int guess(int num){
    if( pick > num ) return 1;
    else if(pick < num) return -1;
    else return 0;
}

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

/**
 * bisection algorithm
 *
 * I tried c = (b + e)/2, but failed because b + e may exceed INT_MAX.
 * Here b/2 + e/2 should be nice, but when b = e = odd then c is wrong.
 * So I try c = b/2 + e/2 + b%2, this passed.
 */
class Solution {
public:
    int guessNumber(int n) {
        int b = 1, c, guessed;
        do{
            c = (b >> 1) + ( n >> 1 ) + (b & 1);
            guessed = guess( c );
            if( guessed == 1 ) b = c+1;
            else if( guessed == -1 ) n = c-1;
            else return c;
        }while(true);
    }
};

/**
 * more directly, let c = b + (e - b)/2
 */
class Solution2 {
public:
    int guessNumber(int n) {
        int b = 1, c, guessed;
        do{
            c = b + (n - b)/2;
            guessed = guess( c );
            if( guessed == 1 ) b = c+1;
            else if( guessed == -1 ) n = c-1;
            else return c;
        }while(true);
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // case in Leetcode Problem
    pick = 6;
    cout << sol.guessNumber( 10 ) << endl;
    cout << sol2.guessNumber( 10 ) << endl;
    
    // case in Leetcode Judgement. 
    pick = 1702766719;
    cout << sol.guessNumber( 2126753390 ) << endl;
    cout << sol2.guessNumber( 2126753390 ) << endl;

    return 0;
}