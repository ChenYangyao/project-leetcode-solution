#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by moving bit out from n in the right, and flowing into m toward left.
 * We do not use a for-loop. When n is a small integer, e.g. 000...0001, we only 
 * need to move the several least-significant bits out from n, not 32 bits.
 */ 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 0, m = 0;
        do{
            m = (m << 1) + (n & uint32_t(1));
            ++i;
        }while( n >>= 1 );
        return m << (uint32_t(32)-i);
    }
};


/**
 * a simple test example
 */ 
void print_uint32_bits(uint32_t n){
    for(uint32_t i=0; i<32; ++i){
        uint32_t j = (n << i) >> 31;
        cout << j;
    }
    cout << endl;
}
int main(int argc, char const *argv[]){
    Solution sol;

    uint32_t n = 4;
    print_uint32_bits(n);
    print_uint32_bits(sol.reverseBits(n));
    return 0;
}