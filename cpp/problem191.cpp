#include <mystd.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int cnt = 0;
        while(n){
        	cnt += n & 1u;
        	n >>= 1;
        }
        return cnt;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// cases in Leetcode Problem
	cout << sol.hammingWeight( 11u ) << endl; 	//00000000000000000000000000001011
	cout << sol.hammingWeight( 128u ) << endl;	//00000000000000000000000010000000
	cout << sol.hammingWeight( 0xffffffff - 2u ) << endl;	//11111111111111111111111111111101
	return 0;
}