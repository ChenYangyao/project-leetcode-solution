#include <mystd.h>
using namespace std;

/**
 * solution by finding maximal number of continuous '0' in the input
 *
 * The first and the last piece of continuous '0' should be treat specially,
 * we do this by two while(s).
 *
 * Time: O(n); No extra space.
 */
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	// first and last several '0'
    	int first1 = 0, last1 = seats.size();
		while( !seats[first1++] );
		while( !seats[--last1] );
		
		// find each continuous piece of 0 (begin at index 'bindx'), 
		// calculate the length of it, keep record of the maximal length by
		// maxdis.
		int bval = 0, bindx = first1, maxdis = 0;
		for (int i = first1; i <= last1; ++i){
			if( seats[i] != bval ){
				if( bval == 0 ) maxdis = max(maxdis, i - bindx);
				else bindx = i;
				bval = seats[i];
			}
		}

		// compare lengths of first piece, last piece and intermediate piece.
		last1 = seats.size() - last1 - 1;
		first1 -= 1;
		maxdis = (maxdis + 1)/2;
		return ( last1 > first1 )?max(last1,maxdis):max(first1,maxdis);
    }
};

int main(int argc, char const *argv[]){
	Solution sol;

	// test case in Leetcode Problem
	vector<int> v = {1,0,0,0,1,0,1};
	cout << sol.maxDistToClosest(v) << endl;
	v.assign({1,0,0,0});

	// some extreme cases
	cout << sol.maxDistToClosest(v) << endl;
	v.assign({0,0,0,0,1,0,0,0});
	cout << sol.maxDistToClosest(v) << endl;
	v.assign({0,0,0,0,1});
	cout << sol.maxDistToClosest(v) << endl;
	return 0;
}