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
 * solution by post-order DFS, recursively
 */ 
class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        int l = 0;
        longestUnivaluePath(root, l);
        return l;
    }
    int longestUnivaluePath(TreeNode *p, int &l){
        if( !p ) return 0;
        int childh, h = 0, templ = 0;
        if( (childh = longestUnivaluePath(p->left, l)) && p->val == p->left->val ){
            templ += childh;
            h = childh;
        }
        if( (childh = longestUnivaluePath(p->right, l)) && p->val == p->right->val ){
            templ += childh;
            h = max(h, childh);
        }
        l = max(l, templ);
        return h + 1;
    }
};

/**
 * same as abovee but implemented iteratively
 */ 
class Solution2 {
public:
    struct StkItem{
        TreeNode *p;
        int lh = 0, rh = 0;
        int &h;
        StkItem(TreeNode *_p, int &_h): p(_p), h(_h){ }
    };
    int longestUnivaluePath(TreeNode *root) {
        stack<StkItem> stk;
        int h = 0, l = 0;
        if( root ) stk.emplace(root, h);
        while( !stk.empty() ){
            auto &top = stk.top();
            if( top.h ){
                int templ = 0;
                if( top.lh && top.p->left->val == top.p->val ){
                    top.h += top.lh;
                    templ += top.lh;
                }
                if( top.rh && top.p->right->val == top.p->val ){
                    top.h = max(top.rh+1, top.h);
                    templ += top.rh;
                }
                l = max(l, templ);
                stk.pop();
            }else{
                if( top.p->left ) stk.emplace(top.p->left, top.lh);
                if( top.p->right ) stk.emplace(top.p->right, top.rh);
                top.h = 1;
            }
        }
        return l;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // test cases in Leetcode Problem
    vector<int> v = {5,4,5,1,1,-1,5};
    Tree tr( v, -1 );
    cout << sol.longestUnivaluePath(tr.root()) << endl;
    cout << sol2.longestUnivaluePath(tr.root()) << endl;

    v.assign({5,4,5,4,4,-1,5});
    tr = Tree( v, -1 );
    cout << sol.longestUnivaluePath(tr.root()) << endl;
    cout << sol2.longestUnivaluePath(tr.root()) << endl;
    return 0;
}


