#include <mystd.h>
using namespace std;

/**
 * This behaves like a stack, we begin with the top, use '#' to cancel the 
 * element below it, find the first un-cancelled element and compare it with
 * the counter part in another stack. 
 * The loop continues until one stack is empty, or the un-cancelleds of two
 * stacks mismatch.
 *
 * Time: linear with len(S) + len(T), space: constant. 
 */
class Solution {
public:
    bool backspaceCompare(string S, string T) {
    	int i = S.size() - 1, j = T.size() - 1;
    	bool res = true;
    	do{
    		next( S, i ); next(T, j);
    		if( i < 0 ){
    			if( j >= 0 ) res = false;
    			break;
    		}else if( j < 0 ){
    			res = false;
    			break;
    		}else if( S[i] != T[j] ){
    			res = false;
    			break;
    		}
    		--i; --j;
    	}while( true );
    	return res;
    }
    void next( string &s, int &i){
    	int count =  s[ i ] == '#'? -1 : 1;
    	while( count <= 0 && ( --i >= 0 )  ){
    		count = s[ i ] == '#' ? (count - 1) : ( count + 1 );
    	}
    }
};

void check(string S, string T){
	Solution sol;
	cout << S << ", " << T << ": " << sol.backspaceCompare(S,T) << endl;
}

int main(int argc, char const *argv[]){
	// test example in Leetcoe problem
	check("ab#c", "ad#c");
	check("ab##", "c#d#");
	check("a##c", "#a#c");
	check("a#c", "b");
	
	return 0;
}

