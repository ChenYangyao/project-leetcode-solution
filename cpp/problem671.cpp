#include <mystd.h>
#include "BinaryTree.h"
using namespace std;
typedef MYDS::BinaryTreeNode<int> TreeNode;
typedef MYDS::BinaryTree<int> Tree;

/**
 * tree in this problem is a minimal heap, so we use algorithm like the 'heap-sort'
 * to find the second minimal value.
 *
 * Trick: 
 * (1) to keep the shape of this tree, we merely set the top value to be INT_MAX, 
 * instead of removing it from the tree.
 * (2) sift_down is the key algorithm of heap, so we write it to be an independent subroutine.
 *
 * This algorithm exploit the property of a heap, so only constant space is used. On average
 * the time cost is only log(n), but in the worst case it could be n*log(n).
 */
class Solution {
public:
	typedef TreeNode * p_type;
    int findSecondMinimumValue(TreeNode* root) {
    	if( !root ) return -1;
		int minval = root->val;
		do{
			root->val = INT_MAX;
			sift_down(root);
			if( root->val != minval ) return root->val == INT_MAX ? -1: root->val;
		}while( true );
    }
   void sift_down( p_type p ){
		int temp = p->val;
		while( p->left ){
			if( p->left->val < p->right->val ){
				if( temp <= p->left->val ) break;
				else{
					p->val = p->left->val;
					p = p->left;
				}
			}else{
				if( temp <= p->right->val ) break;
				else{
					p->val = p->right->val;
					p = p->right;
				}
			}
		}
		p->val = temp;
    }
};

/**
 * or, we just treat the input a an ordinary tree, and use DFS to find the answer.
 * Space cost: log(n), in the worst case it could be n
 * Time cost: fixed n
 */
class Solution2{
public:
	typedef TreeNode * p_type;
    int findSecondMinimumValue(TreeNode* root) {
    	if( !root ) return -1;
    	stack<p_type> stk; stk.emplace(root);
    	int minval = root->val, secondminval = INT_MAX;
    	while( !stk.empty() ){
    		auto *top = stk.top(); stk.pop();
    		if( top->val > minval ) secondminval = min( secondminval, top->val );
    		if( top->left ){
    			stk.emplace(top->right); stk.emplace(top->left);
    		}
    	}
    	return secondminval == INT_MAX ? -1: secondminval;
    }
};


int main(int argc, char const *argv[]){
	// test cases in the Leetcode website.
	vector<int> v = {2,2,5,-1,-1,5,7};
	Tree tr(v, -1);
	Solution sol; Solution2 sol2;
	cout << sol2.findSecondMinimumValue( tr.root() ) << endl;
	cout << sol.findSecondMinimumValue( tr.root() ) << endl;
	cout << tr << endl;

	v.assign( {2,2,2,2,2,2,5} ); tr = Tree(v, -1);
	cout << sol2.findSecondMinimumValue( tr.root() ) << endl;
	cout << sol.findSecondMinimumValue( tr.root() ) << endl;
	cout << tr << endl;

	v.assign( {2,2,2,2,2,2,2} ); tr = Tree(v, -1);
	cout << sol2.findSecondMinimumValue( tr.root() ) << endl;
	cout << sol.findSecondMinimumValue( tr.root() ) << endl;
	cout << tr << endl;
	return 0;
}