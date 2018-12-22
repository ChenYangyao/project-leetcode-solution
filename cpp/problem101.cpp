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
 * determine whether two trees are a mirror, recursively
 * this is almost copied from problem 100
 */
class IsIdenticalRecursively {
public:
    bool operator()(TreeNode* p, TreeNode* q) {
        if( p && q ){
            return p->val == q->val && (*this)(p->left, q->right) && (*this)(p->right, q->left);
        }else if( p || q ){
            return false;
        }else{
            return true;
        }
    }
};

/**
 * determine whether two trees are a mirror, iteratively
 * this is almost copied from problem 100
 */
class IsIdenticalIteratively {
public:
    bool operator()(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1, stk2;
        if( p ) stk1.push(p);
        if( q ) stk2.push(q);

        while( !stk1.empty() ){
            if( stk2.empty() ) return false;
            p = stk1.top(); stk1.pop();
            q = stk2.top(); stk2.pop();
            if( p->val != q->val ) return false;
            if( p->right ){
                if( q->left ){
                    stk1.push(p->right); stk2.push(q->left);
                }else
                    return false;
            }else if( q->left ) return false;

            if( p->left ){
                if( q->right ){
                    stk1.push(p->left); stk2.push(q->right);
                }else
                    return false;
            }else if(q->right) return false;
        }
        return stk2.empty()? true: false;
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( !root ) return true;
        return IsIdenticalRecursively()( root->left, root->right );
    }
};


class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if( !root ) return true;
        return IsIdenticalIteratively()( root->left, root->right );
    }
};


int main(int argc, char const *argv[]){
    vector<int> v = {1,2,2,3,4,4,3}, v2 = {1,2,2,-1,3,-1,3};
    Tree tr( v, -1 ), tr2( v2, -1 );

    cout << Solution().isSymmetric( tr.root() ) << endl;
    cout << Solution().isSymmetric( tr2.root() ) << endl;
    cout << Solution2().isSymmetric( tr.root() ) << endl;
    cout << Solution2().isSymmetric( tr2.root() ) << endl;
    
    return 0;
}