#include <mystd.h>
#include "BinaryTree.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef MYDS::BinaryTree<int> Tree;
typedef typename Tree::node_type TreeNode;




/**
 * helper class for identifying whether two tree are identical
 */
class TreeIsIdentical{
public:
	/**
	 * return true if two trees rooted from r1 and r2 are identical
	 *
	 * This takes O( min( M, N ) ) time, where M, N are number of 
	 * nodes in r1 and r2, respectively.
	 */
	bool operator()(TreeNode *r1, TreeNode *r2){
		if( (r1 && !r2) || (r2 && !r1) ) return false;
		bool res = true;
		if( r1 ) stk1.push( r1 );
		if( r2 ) stk2.push( r2 );
		while( !stk1.empty() ){
			auto top1 = stk1.top(); stk1.pop();
			auto top2 = stk2.top(); stk2.pop();
			if( top1->val != top2->val ){ res = false; break; }
			if( top1->right ){
				if( ! top2->right ){ res = false; break; }
				stk1.push( top1->right );
				stk2.push( top2->right );
			}else if( top2->right ){ res = false; break; }
			if( top1->left ){
				if( ! top2->left ){ res = false; break; }
				stk1.push( top1->left );
				stk2.push( top2->left );
			}else if( top2->left ){ res = false; break; }
		}
		while( !stk1.empty() ) stk1.pop();
		while( !stk2.empty() ) stk2.pop();
		return res;
	}
	/**
	 * return number of nodes in tree rooted from r
	 *
	 * This takes O(M) times, where M is number of nodes in r.
	 */
	int numberNodes(TreeNode *r){
		int res = 0;
		if( r ) stk1.push(r);
		while( !stk1.empty() ){
			auto top = stk1.top(); stk1.pop();
			++res;
			if( top->right ) stk1.push( top->right );
			if( top->left ) stk1.push( top->left );
		}
		return res;
	}
	stack<TreeNode *> stk1, stk2;
};

/**
 * solution by comparing t with each sub-tree of s
 *
 * Each comparison takes O( min(M,N) ) time. Where M, N are number of 
 * nodes in s and t, respectively. 
 * The DFS takes O(M) time.
 * Put them together, we have the time upper boune O( M *min(M,N) ).
 * In more realistic case, where N < M, the time complexity is O(M*N).
 * 
 * The solution takes O( log(M) ) space, on average, with no dependence
 * on N (even if we consider the space in calling of treeIsIdentical(), you
 * may do some mathematical analysis to find that ).
 */
class Solution {
public:
	/**
	 * Pre-order traversal is iteratively used to get each sub-tree 'sub-s',  of s
	 * For each sub-s, we compare it with t.
	 */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        TreeIsIdentical treeIsIdentical;
        stack<TreeNode *> stk;
        if( s ) stk.push( s );
        while( !stk.empty() ){
        	auto top = stk.top(); stk.pop();
        	if( treeIsIdentical( top, t ) ) return true;
        	if( top->left ) stk.push( top->left );
        	if( top->right ) stk.push( top->right );
        }
    	return false;
    }
};

/**
 * solution by comparing t with each sub-tree 'sub-s' of s, with restriction that the
 * number of nodes #(t) == #(sub-s)
 *
 * In this method, we first get the number of nodes in t, #(t). Then the DFS of s gives
 * the number of nodes in each sub-s, #(sub-s). Only when #(t) == #(sub-s) we compare t
 * with sub-s. You may find that this saves much time.
 *
 * The time for get #(t) is O(N).
 * The comparison of all sub-s with t takes O(M) time. 
 * Where M, N are number of nodes in s and t, respectively. 
 * The final time upper bound, from detail calculation, is O( max(M, N) ).
 * In more realistic case, where N < M, the time complexity is O(M), much better than
 * solution 1.
 *
 * The space cost is O( log(max(M, N)) ). If N < M, it is still O( log(M) ).
 */
class Solution2 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	TreeIsIdentical treeIsIdentical;
    	int num_nodes_t = treeIsIdentical.numberNodes( t );

        stack<StkItem> stk;
        int num_nodes_s = 0;
        if( s ) stk.emplace( s, &num_nodes_s );
        while( !stk.empty() ){
        	auto &top = stk.top();
        	if( top.visited ){
        		int nnodes = top.nleft + top.nright + 1;
        		*(top.nnodes) = nnodes;
        		if( nnodes == num_nodes_t && treeIsIdentical( top.p, t ) ) 
        			return true;
        		stk.pop();
        	}else{
        		top.visited = true;
        		if( top.p->right ) stk.emplace( top.p->right, &top.nright );
        		if( top.p->left ) stk.emplace( top.p->left, &top.nleft );
        	}
        }
        return false;
    }
    struct StkItem{
    	TreeNode *p;
    	int *nnodes;
    	int nleft = 0, nright = 0;
    	bool visited = false;
    	StkItem( TreeNode *_p, int *_nnodes ): p(_p), nnodes(_nnodes){ }
    };
};


int main(int argc, char const *argv[]){
	Solution sol;
	Solution2 sol2;
	// cases in Leetcode problem
	{
		vector<int> vs = {3,4,5,1,2,-1,-1,-1,-1,0}, vt = {4,1,2};
		Tree s( vs, -1 ), t( vt, -1 );
		cout << sol.isSubtree( s.root(), t.root() ) << endl;
		cout << sol2.isSubtree( s.root(), t.root() ) << endl;
	}
	{
		vector<int> vs = {3,4,5,1,2}, vt = {4,1,2};
		Tree s( vs, -1 ), t( vt, -1 );
		cout << sol.isSubtree( s.root(), t.root() ) << endl;
		cout << sol2.isSubtree( s.root(), t.root() ) << endl;
	}
	return 0;
}