#include <mystd.h>
#include "BinaryTree.h"
using namespace MYSTD;
using namespace std;

typedef MYDS::BinaryTree<int> Tree;
typedef typename Tree::node_type TreeNode;
/** 
 * Definition for a binary tree node.
 * struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * solution with pre-order DFS recursively
 * During the DFS, leaf node is identified and its depth is compared
 * with the minDepth that has been already found.
 */ 
class Solution {
public:
    int minDepth(TreeNode *root) {
        if( !root ) return 0;
        int minDepth = INT_MAX;
        _minDepth( root, 1, minDepth );
        return minDepth;
    }
    void _minDepth(TreeNode *p, int depth, int &minDepth){
        if( !p ) return;
        if( !(p->left || p->right)  ) minDepth = min(minDepth, depth);
        _minDepth(p->left, depth+1, minDepth);
        _minDepth(p->right, depth+1, minDepth);
    } 
};

/**
 * similar to above, but use iteration
 */ 
class Solution2 {
public:
    struct StkItem {
        TreeNode *p;
        int depth;
        StkItem(TreeNode *_p, int _depth):p(_p), depth(_depth){}
    };
    int minDepth(TreeNode* root) {
        stack<StkItem> stk;
        if( root ) stk.emplace(root, 1); else return 0;
        int minDepth = INT_MAX;
        while( !stk.empty() ){
            StkItem top = stk.top(); stk.pop();
            if( !(top.p->left || top.p->right) ) minDepth = min( minDepth, top.depth );
            if( top.p->left ) stk.emplace( top.p->left, top.depth + 1 );
            if( top.p->right ) stk.emplace( top.p->right, top.depth + 1 );
        }
        return minDepth;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    
    // test case in Leetcode Problem
    vector<int> v = { 3,9,20,-1,-1,15,7 };
    Tree tr( v, -1 );
    cout << sol.minDepth(tr.root()) << ' ' << sol2.minDepth(tr.root()) << endl;

    return 0;
}
