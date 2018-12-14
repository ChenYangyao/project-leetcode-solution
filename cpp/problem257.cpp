#include "mystd.h"
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
typedef MYDS::BinaryTreeNode<int> TreeNode;
typedef MYDS::BinaryTree<int> Tree;


/**
 * recursive algorithm
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if( root ){
        	string s = to_string(root->val);
        	binaryTreePaths(root, s, res);
        }
        return res;
    }
    void binaryTreePaths(TreeNode *p, string &s, vector<string> &res){
    	bool has_child = false;
    	if( p->left ){
    		has_child = true;
    		string temps = s + "->" + to_string(p->left->val);
    		binaryTreePaths( p->left, temps, res );
    	}
    	if( p->right ){
    		has_child = true;
    		string temps = s + "->" + to_string(p->right->val);
    		binaryTreePaths( p->right, temps, res );	
    	}
    	if( !has_child ){
    		res.emplace_back( s );
    	}
    }
};

/**
 * iterative algorithm
 */
class Solution2 {
public:
	struct StkItem{
		TreeNode *p;
		string s;
		bool is_visited = false;
		StkItem( TreeNode *_p, const string & _s ): p(_p), s(_s){}
	};
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> res;
    	stack<StkItem> stk;
    	if( root ) stk.emplace( root, to_string( root->val ) );
    	while( !stk.empty() ){
    		auto &top = stk.top();
    		if( top.is_visited ){
    			if( !(top.p->left || top.p->right) ) res.emplace_back( top.s );
    			stk.pop();
    		}else{
    			top.is_visited = true;
    			if( top.p->right ) stk.emplace( top.p->right, top.s + "->" + to_string(top.p->right->val) );
    			if( top.p->left ) stk.emplace( top.p->left, top.s + "->" + to_string(top.p->left->val) );
    		}
    	}
    	return res;
    }

};


int main(int argc, char const *argv[]){
	vector<int> ints = {1,2,3,4,5,-1,-1,-1,7};
	Tree tree(ints, -1);
	Solution sol; 
	Solution2 sol2;
	auto res = sol.binaryTreePaths( tree.root() );
	for(auto & i: res){
		cout << i << endl;
	}
	res = sol2.binaryTreePaths( tree.root() );
	for(auto & i: res){
		cout << i << endl;
	}

	return 0;
}