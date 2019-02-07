#include <mystd.h>
#include "BinaryTree.h"
using namespace std;
using namespace MYSTD;
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
 * solution by pre-order traversal, implemented recursively
 * 
 * Time: Theta(n), space Theta(log(n))
 * 
 * Author: Yangyao Chen, 2019/02/02
 */ 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root, 0, sum);
    }
    bool hasPathSum(TreeNode* root, int sumAbove, int sum){
        if( !root ) return false;
        sumAbove += root->val;
        if( !(root->left || root->right) ) return sumAbove == sum;
        return hasPathSum(root->left, sumAbove, sum) || hasPathSum(root->right, sumAbove, sum);
    }
};

/**
 * same as above, but implemented interatively
 */ 
class Solution2 {
public:
    struct stkitem_t {
        TreeNode *p;
        int sumAbove;
        stkitem_t( TreeNode *_p, int _sumAbove ) : p(_p), sumAbove(_sumAbove){}
    };
    bool hasPathSum(TreeNode* root, int sum) {
        stack<stkitem_t> stk;
        if( root ) stk.emplace( root, 0 );
        while( !stk.empty() ){
            auto &top = stk.top();
            auto *p = top.p;
            int sumAbove = top.sumAbove + p->val;
            stk.pop();
            if( !(p->left || p->right) ){ 
                if( sumAbove == sum ) return true; 
            }else{
                if( p->left ) stk.emplace( p->left, sumAbove );
                if( p->right ) stk.emplace( p->right, sumAbove );
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    
    // case in Leetcode Problem
    vector<int> v = {5,4,8,11,-1,13,4,7,2,-1,1};
    Tree tr( v, -1 );

    cout << sol.hasPathSum( tr.root(), 22 ) << endl;
    cout << sol2.hasPathSum( tr.root(), 22 ) << endl;

    return 0;
}
