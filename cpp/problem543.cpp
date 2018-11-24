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
 * recursive method
 * The key is:
 *  - for the maximal diameter d of routine that pass the node p as root,
 *      we must have d = height(p->left) + height(p->right).
 *  - so we can post-order visit each node, after calculating the height of its two children.
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_tot_height = 0;
        heightOfNode(root, max_tot_height);
        return max_tot_height;
    }
    int heightOfNode(TreeNode* p, int &max_tot_height){
        if( !p ) return 0;
        int lheight = heightOfNode( p->left, max_tot_height ),
            rheight = heightOfNode( p->right, max_tot_height );
        max_tot_height = max( lheight + rheight, max_tot_height );
        return max(lheight, rheight) + 1;
    }
};

/**
 * iterative method
 * The idea is same as the recursive one.
 */
class Solution2{
public:
    struct StkNode{
        TreeNode *p;
        int hleft = -1, hright = -1;
        int &hthis;
        StkNode(TreeNode *_p, int &_hthis):p(_p), hthis(_hthis){}
    };
    int diameterOfBinaryTree(TreeNode* root) {
        int max_tot_height = 0, rootheight = 0;
        stack<StkNode> stk;
        if(root) stk.emplace( root, rootheight );
        while(!stk.empty()){
            auto &top = stk.top();
            if( !top.p ){
                top.hthis = 0;
                stk.pop();
            }else if( top.hleft < 0 ){
                stk.emplace( top.p->left, top.hleft );
                stk.emplace( top.p->right, top.hright );
            }else{
                max_tot_height = max(max_tot_height, top.hleft + top.hright);
                top.hthis = max(top.hleft, top.hright) + 1;
                stk.pop();
            }
        }
        return max_tot_height;
    }
};



int main(int argc, char const *argv[]){
    // test by the example in the Leetcode problem
    vector<int> v = {1,2,3,4,5};
    Tree tr(v, -1);
    cout << tr;

    Solution sol;
    Solution2 sol2;

    cout << sol.diameterOfBinaryTree(tr.root()) << endl;
    cout << sol2.diameterOfBinaryTree(tr.root()) << endl;
    return 0;
}
