#include <mystd.h>
using namespace std;

/**
 * simply add each bit of two numbers
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz = min( num1.size(), num2.size() ), 
        	inc_bit = 0;
        string s;
        auto i1 = &num1.back(), i2 = &num2.back();
        for (int i = 0; i < sz; ++i){
        	int this_bit = (*i1 - '0') + (*i2 - '0') + inc_bit;
        	inc_bit = this_bit >= 10;
        	this_bit %= 10;
        	s  += char( '0' + this_bit );
        	--i1;
        	--i2;
        }
        if( num1.size() > sz ) padd_remaining( num1, sz, inc_bit, s ); 
        else padd_remaining( num2, sz, inc_bit, s );
        reverse(s.begin(), s.end());
        return s;
    }
    void padd_remaining( string &num, int sz, int inc_bit, string &s ){
    	for (int i =  num.size() - sz - 1; i >= 0; --i){
    		int this_bit = (num[i] - '0') + inc_bit;
    		inc_bit = this_bit >= 10;
    		this_bit %= 10;
    		s += char( '0' + this_bit);
    	}
    	if( inc_bit ) s += '1';
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	string num1 = "134", num2 = "999";
	cout << sol.addStrings(num1, num2) << endl;

	return 0;
}
