#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution with Dijkstra algorithm
 */

class Solution{
public:
	int rabbitCrossRiver( int n, int m, vector<int> &x, vector<int> &y){
		// convert x[m]->y[m] into a hash-map 'jump', allowing faster searching 
		unordered_map<int, int> jumps;
		for (int i = 0; i < m; ++i){
			jumps[x[i]] = y[i];
		}

		// 'lens' records the currecnt (candidate) shortest paths, from node 0 to other nodes.
		// lens[i] == INT_MAX means node i is not accessible currecntly
		// 'acc' record all the current accesible nodes from node 0.
		vector<int> lens( n + 2, INT_MAX );
		lens[0] = 0;
		
		unordered_set<int*> acc;
		acc.emplace(&lens[0]);
		
		// Once we have already found the real shortest path from node 0 to i, lens[i] is set to -1, node i
		// is removed from acc. We also update the candidates by the linkages fron node i.
		int *p = nullptr;
		while( (p = find_shortest_path( acc )) != & lens.back() ) {
		    auto it = jumps.find( p - lens.data() );
		    if( it != jumps.end() ){
		    	if( lens[it->second] >= 0 ){
		    		if( lens[it->second] == INT_MAX ) acc.emplace( &lens[it->second] );
		    		lens[it->second] = min( lens[it->second], *p );
		    	}
		    }else{
		    	for (int i = 1; i <= 3 && p + i <= &lens.back() ; ++i){
		 			if( *(p + i) >= 0 ){
			    		if( *(p + i) == INT_MAX ) acc.emplace( p + i );
			    		*(p + i) = min( *(p + i), *p + 1 );
		 			}
		    	}
		    }
		    *p = -1;
		}
		return *p;
	}
	/**
	 * from the accessible nodes, pick the one whose real shortest path is determined
	 * It is just the accessible node whose path is the shortest among all candidates. 
	 */
	int * find_shortest_path( unordered_set<int*> &acc ){
		int len = INT_MAX;
		auto it = acc.begin(), res_it = it;
		for (; it != acc.end(); ++it){
			if( **it < len ){
				res_it = it;
				len = **it;
			}
		}
		int *p = *res_it;
		acc.erase( res_it );
		return p;
	}
};

int main(int argc, char const *argv[]){
	// test case in the Problem
	int n = 8, m = 3;
	vector<int> x = {1,3,6}, y = {4,5,8};

	Solution sol;
	cout << sol.rabbitCrossRiver( n,m,x,y ) << endl; 

	return 0;
}