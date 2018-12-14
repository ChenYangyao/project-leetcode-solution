#include "mystd.h"
using namespace std;

/**
 * a trival question and solution
 * Time and space costs: Theta(n^2)
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int> > res;
    	if( ! numRows ) return res;
    	res.emplace_back( 1, 1 );
    	for (int i = 2; i <= numRows; ++i){
    		res.emplace_back( i, 0 );
    		auto &p = res[ i - 2 ], &q = res[ i-1 ];
    		for (int j = 1; j < i - 1; ++j)  q[ j ] = p[ j-1 ] + p[j];
    		q[ 0 ] = q[ i - 1 ] = 1;
    	}
    	return res;
    }
};


void prt( vector<vector<int>> & v ){
	for(auto & i: v){
		for(auto & j: i){
			cout << j << ' ';
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[]){
	Solution sol;
	auto res = sol.generate(5);

	prt( res );
	
	return 0;
}