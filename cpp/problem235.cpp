#include <mystd.h>
#include "BinaryTree.h"
using namespace std;


typedef MYDS::BinaryTree<int> Tree;
typedef typename Tree::node_type TreeNode;

/**
 * the question is a variant of searching algorithm in BST
 * but stop when the searching pathes of p and q become different.
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto *pre = root;
        while( true ){
        	auto *currp = stepdown( p, pre );
        	auto *currq = stepdown( q, pre );
        	if( currq != currp ) return pre;
        	pre = currp;
        }
    }
    TreeNode* stepdown( TreeNode *p, TreeNode *pre ){
    	TreeNode *res = nullptr;
    	if( p->val < pre->val )res = pre->left;
    	else res = pre->val < p->val ? pre->right : pre;
    	return res;
    }
};


int main(int argc, char const *argv[]){
	// test example in Leetcode question
	vector<int> v = {6,2,8,0,4,7,9,-1,-1,3,5};
	Tree tr(v, -1);
	cout << tr << endl;

	Solution sol;
	cout << sol.lowestCommonAncestor( tr.root(), tr.root()->left, tr.root()->right )->val << endl;
	cout << sol.lowestCommonAncestor( tr.root(), tr.root()->left, tr.root()->left->right )->val << endl;
	
	return 0;
}