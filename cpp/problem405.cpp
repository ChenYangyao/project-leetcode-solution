#include <mystd.h>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res;
        do{
        	res += digitToHex( num & 0xf );
        	*((unsigned*) (&num)) >>= 4;
        }while(num);
        reverse( res.begin(), res.end() );
        return res;
    }
    char digitToHex(int digit){
    	return digit <= 9 ? ('0' + digit) : ( 'a' + (digit - 10) );
    }
};

int main(int argc, char const *argv[]){
	Solution sol;
	cout << sol.toHex(26) << endl;
	cout << sol.toHex(-1) << endl;
	return 0;
}