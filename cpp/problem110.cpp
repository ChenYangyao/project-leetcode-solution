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
 * a simple question that can be easily solved by iterative post-order DFS
 *
 * When visiting a node, we first (conceptually iteratively) visit its left tree 
 * and right tree, obtain the heights of them, and determine whether this node is
 * balanced.
 * The whole tree is balanced iff each node is balanced.
 * 
 * Time: O(n), Space: O(log(n)) 
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	stack<StkItem> stk;
    	int height = 0;
		if( root ) stk.emplace( root, height );
		while( !stk.empty() ){
			auto &top = stk.top();
			if( top.is_visited ){
				if( top.lheight - top.rheight > 1 || top.rheight - top.lheight > 1 ) 
					return false;
				top.height = max(top.lheight, top.rheight) + 1;
				stk.pop();
			}else{
				if( top.p->right ) stk.emplace( top.p->right, top.rheight );
				if( top.p->left ) stk.emplace( top.p->left, top.lheight );
				top.is_visited = true;
			}
		}
		return true;
    }
    struct StkItem{
    	TreeNode *p;
    	bool is_visited = false;
    	int lheight = 0, rheight = 0;
    	int &height;
   		StkItem( TreeNode *_p, int &_height ): p(_p), height(_height){}
    };
};

/**
 * same method, but implemented with recursion
 *
 * Time: O(n), Space: O(log(n)) 
 */
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
    	int height = 0;
    	return isBalanced(root, height);
    }
    bool isBalanced(TreeNode* root, int &height) {
    	if( !root ) return true;
    	int lheight = 0, rheight = 0;
    	if( !(  isBalanced(root->left, lheight ) 
    			&& isBalanced(root->right, rheight) 
    			&& abs(lheight - rheight) <= 1 ) ) 
    		return false;
    	height = max(lheight, rheight) + 1;
    	return true;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;
	Solution2 sol2;

	vector<int> v = {3,9,20,-1,-1,15,7};
	Tree tr1( v, -1 );
	cout << sol.isBalanced( tr1.root() ) << endl;
	cout << sol2.isBalanced( tr1.root() ) << endl;

	v.assign({1,2,2,3,3,-1,-1,4,4});
	Tree tr2( v, -1 );
	cout << sol.isBalanced( tr2.root() ) << endl;
	cout << sol2.isBalanced( tr2.root() ) << endl;
	return 0;
}