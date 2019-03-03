#include <mystd.h>
#include "BinaryTree.h"
using namespace MYSTD;
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
 * pre-order DPS, recursively
 * When root->val is not located in [L,R], one of the subtree of root
 * could be omitted.
 */ 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if( !root ) return 0;
        int sum = 0;
        if( L <= root->val ){
            sum += rangeSumBST( root->left, L, R );
            if( root->val <= R ){ 
                sum += rangeSumBST( root->right, L, R );
                sum += root->val;
            }
        }else{
            sum += rangeSumBST( root->right, L, R );
        }
        return sum;
    }
};

/**
 * same as above, but implemented with iteration
 */ 
class Solution2 {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        
        stack<TreeNode *> stk;
        if( root ) stk.emplace(root);
        while( !stk.empty() ){
            auto *p = stk.top(); stk.pop();
            if( L <= p->val ){
                if( p->left ) stk.emplace(p->left);
                if( p->val <= R ){
                    if(p->right) stk.emplace(p->right);
                    sum += p->val;
                }
            }else{
                if( p->right ) stk.emplace(p->right);
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    
    vector<int> v;

    v = {10,5,15,3,7,-1,18};
    Tree tr{ v, -1 };
    cout << sol.rangeSumBST(tr.root(), 7, 15) << " " << sol2.rangeSumBST(tr.root(), 7, 15) << endl;

    v = {10,5,15,3,7,13,18,1,-1,6};
    tr = Tree( v, -1 );
    cout << sol.rangeSumBST(tr.root(), 6, 10) << " " << sol2.rangeSumBST(tr.root(), 6, 10) << endl;
    return 0;
}