#include <mystd.h>
using namespace std;


class Solution {
public:
    bool isUgly(int num) {
        if( num <= 0 ) return false;
		for(auto denom: {2,3,5}) repeatDivide( num, denom );
		return num == 1;
    }
    static void repeatDivide(int &num, int denom){
    	while( num % denom == 0 ) num /= denom;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	for(auto num: {6,8,14}){
		cout << sol.isUgly(num) << endl;
	}
	return 0;
}