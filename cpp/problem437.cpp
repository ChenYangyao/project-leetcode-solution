#include <mystd.h>
#include "BinaryTree.h"
using namespace std;
typedef MYDS::BinaryTree<int> Tree;
typedef typename Tree::node_type TreeNode;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/**
 * DFS implementation, recursively
 * When first encounter a tree node p, we add its value into the path array.
 * Next we count all the sub-arrays, of path, that have sum-value equal to given 'sum'.
 * These are done recursively for the children of p. After that the value of p is removed from path.
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0; 
        vector<int> path;
        pathSum(root, sum, path, cnt);
        return cnt;
    }
    void pathSum(TreeNode*p, int sum, vector<int> &path, int &cnt){
    	if( !p ) return;
    	path.push_back( p->val );
    	int temp_sum = 0;
    	for (int i = path.size() - 1; i >= 0; --i){
    		temp_sum += path[i];
    		if( temp_sum == sum ) ++cnt;
    	}
    	pathSum(p->left, sum, path, cnt);
    	pathSum(p->right, sum, path, cnt);
    	path.pop_back();
    	return;
    }
};

/**
 * DFS implementation, iteratively
 * We maintain a stack for DFS, rather than doing it recursively.
 */
class Solution2 {
public:
    int pathSum(TreeNode* root, int sum) {
       	stack<node_t> stk;
       	if( root ) stk.emplace( root );
       	vector<int> path;
       	int cnt = 0;
       	while( !stk.empty() ){
       		auto &top = stk.top();
       		if( top.tag == 0 ){
       			path.push_back( top.p->val );
       			int temp_sum = 0;
       			for (int i = path.size() - 1; i >= 0; --i){
       				temp_sum += path[i];
       				if( temp_sum == sum ) ++cnt;
       			}
       			if( top.p->right ) stk.push(top.p->right);
       			if( top.p->left ) stk.push(top.p->left);
       			top.tag = 1;
       		}else{
       			stk.pop();
       			path.pop_back();
       		}
       	}
       	return cnt;
    }
protected:
    struct node_t{
    	TreeNode* p;
    	int tag = 0;
    	node_t(TreeNode *_p):p(_p){}
    };
};


int main(int argc, char const *argv[]){
	Solution sol; 
	Solution2 sol2;

	// example in Leetcode problem
	vector<int> v = {10,5,-3,3,2,-100,11,3,-2,-100,1};
	Tree tr(v, -100);
	cout << sol.pathSum( tr.root(), 8 ) << endl;
	cout << sol2.pathSum( tr.root(), 8 ) << endl;
	return 0;
}