#include <mystd.h>
#include "BinaryTree.h"
using namespace MYSTD;
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
 * Solution by in-order DFS
 * 
 * To minimize the memory cost, we find the modes by two runs of DFS.
 * The first run gives number of occurance of mode elements.
 * The second run picks up the modes.
 *
 * Space: O(tree.height); Time: Theta(tree.size).
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if( !root ) return {};

        // first run of in-order, find number of occurance of mode elements
        int mode = INT_MIN, cnt_mode = 0, max_cnt_mode = 0;
        auto find_cnt_mode = [&mode, &cnt_mode, &max_cnt_mode](TreeNode *p){
            if( p->val == mode ) ++cnt_mode;
            else{
                max_cnt_mode = max(max_cnt_mode, cnt_mode);
                mode = p->val;
                cnt_mode = 1;
            }
        };
        inOrder( root, find_cnt_mode );
        max_cnt_mode = max(max_cnt_mode, cnt_mode);
        
        // second run of in-order, pick up modes
        vector<int> res;
        mode = INT_MIN, cnt_mode = 0;
        auto give_cnt_mode = [&mode, &cnt_mode, &max_cnt_mode, &res](TreeNode *p){
            if( p->val == mode ) ++cnt_mode;
            else{
                if( cnt_mode == max_cnt_mode ) res.push_back( mode );
                mode = p->val;
                cnt_mode = 1;
            }
        };
        inOrder( root, give_cnt_mode );
        if( cnt_mode == max_cnt_mode ) res.push_back(mode);

        return res;
    }
    /**
     * in-order visiting by any function f
     */ 
    void inOrder(TreeNode* root, function<void(TreeNode *)> f) {
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while( p || !stk.empty() ){
            while(p){
                stk.emplace(p);
                p = p->left;
            }
            p = stk.top(); stk.pop();
            f(p);
            p = p->right;
        }
    }
};


int main(int argc, char const *argv[]){
    // test case in Leetcode Problem
    vector<int> v = {1,-1,2,2};
    Tree tree(v, -1);
    cout << tree;

    Solution sol;
    auto res = sol.findMode( tree.root() );
    MYFILE::print_range( res ) << endl;

    return 0;
}
