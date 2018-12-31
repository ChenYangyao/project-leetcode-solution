#include <mystd.h>
using namespace std;
using namespace MYSTD;


/**
 * solution from the definition of Pascal Triangle
 * Here we use the symmetry of Pascal Triangle in order to accelerate the interation
 * 
 * Author: Yangyao, 2019/01/01
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> res( rowIndex + 1 );
		int cent = 0, row = 0;			// 'cent' is the index of central element of the current row
		res[0] = 1;
		while( ++row <= rowIndex ){
			int i = cent;
			if( !(row & 1) ){ 			// for even row, the central index increases
				res[cent+1] = res[cent] + res[cent];
				++cent;
			}
			for (; i >= 1; --i) res[i] += res[i-1];
										// definition of Pascal Triangle
		}
		int i = cent + 1;
		if( !(rowIndex & 1) ) --cent;
		while( cent >= 0 ) 
			res[ i++ ] = res[ cent-- ];	// Symmetry
		return res;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	for (int i = 0; i < 10; ++i){
		MYFILE::print_range( sol.getRow(i) ) << endl;
	}
	
	return 0;
}
