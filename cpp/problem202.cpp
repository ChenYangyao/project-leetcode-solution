#include <mystd.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        do{
        	if( n == 1 ) return true;
        	st.emplace(n);
        	n = squareDigits(n);
        }while( st.find( n ) == st.end() );
        return false;
    }
    int squareDigits(int n){
    	int res = 0 ;
    	while( n ){
    		int rem = n % 10;
    		res += rem*rem;
    		n /= 10;
    	}
    	return res;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	cout << sol.isHappy( 19 ) << endl;
	return 0;
}