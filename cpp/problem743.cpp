#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * a trivial application of Dijkstra algorithm
 * 
 * This is a single-source-multiple-destination shortest-path problem, we just
 * repeat the idea of Dijkstra, find the shortest pathes from K to all the other nodes,
 * and output the largest one of the shortest pathes.
 *
 * Time complexity: O(N^2) - Dijkstra for strong connected graph.
 * Space complexity: O( max(times.length, N) ) - Mainly for the link table.
 *
 * Author: Yangyao, 2018/01/19
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        init_link_table( times, N );
        init_path(times, N, K);
        int nodeid;
        while( (nodeid = find_path()) >= 0 ){
        	update_path(times, nodeid);
        }
        int max_pathlen = *max_element( pathlen.begin(), pathlen.end() );
        return max_pathlen == INT_MAX ? -1 : max_pathlen;
    }
protected:
	void init_link_table(vector<vector<int> > &times, int N){
		link_tab.assign( N, vector<int>() );
		for(auto & time: times){
			link_tab[ time[0] - 1 ].push_back( &time - times.data() );
		}
	}
	void init_path( vector<vector<int> > &times ,int N, int K){
		pathlen.assign(N, INT_MAX); haspath.assign( N, 0 ); 
		pathlen[K - 1] = 0; haspath[K - 1] = 1;
		for(auto link: link_tab[K - 1]){
			pathlen[times[link][1] - 1] = times[link][2];
		}
	}
	int find_path(){
		int nodeid = -1, minpath = INT_MAX;
		for (int i = 0, n = pathlen.size(); i < n; ++i){
			if( !haspath[i] && pathlen[i] < minpath ){
				nodeid = i; minpath = pathlen[i];
			}
		}
		return nodeid;
	}
	void update_path(vector<vector<int> > &times, int nodeid){
		haspath[nodeid] = 1;
		for(auto link: link_tab[nodeid]){
			pathlen[ times[link][1] - 1 ] = min( pathlen[ times[link][1] - 1 ], 
				pathlen[nodeid] + times[link][2] );
		}
	}
	/**
	 * Here the graph could be strong connected (the problem states times.length could 
	 * be as large as 6000) so it is better if we convert the edge lists into a link table.
	 * To minimize the memory use, we just keep record of the indexes in edge lists for 
	 * each out-node.
	 */
	vector<vector<int> > link_tab;
	/**
	 * The implementation of Dijkstra is to repeatedly identify the current best path for 
	 * node that has not been identified. Here pathlen keeps record of the currect minimal
	 * path lengths from K to all nodes, while haspath keeps record of those whose best
	 * path has been found
	 */
	vector<int> pathlen;
	vector<char> haspath;
};


int main(int argc, char const *argv[]){
	// test case by myself, here N = 5, K = 5
	// Node K has only one path to each other node.
	// The maximal path length should be 4 (5->4).
	vector<vector<int> > times;
	times.push_back( {5,1,1} );
	times.push_back( {5,2,2} );
	times.push_back( {5,3,3} );
	times.push_back( {5,4,4} );
	{
		Solution sol;	
		cout << sol.networkDelayTime( times, 5, 5 ) << endl;
	}
	
	// If we add a intermediate edge 2->4, now
	// path 5->2->4 has length 3, less than 4.
	// The maximal path length should changed to be 3 (5->2->4)
	times.push_back( {2,4,1} );
	{
		Solution sol;	
		cout << sol.networkDelayTime( times, 5, 5 ) << endl;
	}

	return 0;
}