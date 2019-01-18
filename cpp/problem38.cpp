#include <mystd.h>
using namespace std;
using namespace MYSTD;

class Solution {
public:
    string countAndSay(int n) {
		string s("1");
		for (int i = 0; i < n-1; ++i){
			countAndSayOnce( s );
		} 
		return s;
    }
    void countAndSayOnce(string & s){
    	string temp = "";
    	int i = 0, n = s.size();
    	for (int j = 1; j < n; ++j){
    		if( s[j] != s[i] ){
    			temp += to_string( j - i ) + s[i];
    			i = j;
    		}
    	}
    	temp += to_string( n - i ) + s[i];
    	s = std::move( temp );
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	for (int i = 1; i <= 30; ++i){
		cout <<  sol.countAndSay(i) << endl;	
	}
	return 0;
}