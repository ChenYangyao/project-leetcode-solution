#include <iostream>
#include <cmath>
using namespace std;



class Solution {
public:
    int findComplement(int num) {
        int val = 0;
        int base = 1;
        while( num ){
            val += ( (num % 2) ^ 1 ) * base;
            num /= 2;
            base *= 2;
        }
        return val;
    }
};
