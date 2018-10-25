#include "mystd.h"
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void prt_nodes( TreeNode *p ){
    if( p ){
        prt_nodes( p->left );
        cout << p->val << endl;
        prt_nodes( p->right );
    }
}


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode head(0), *p = &head, *q = nullptr;
        head.left = q = root;
        while( q ){
            if( L < q->val ){ p = q; q = q->left; }
            else if( q->val < L ){ p->left = q->right; q->right = nullptr; delSubtree( q ); q = p->left; }
            else{
                delSubtree( q->left ); q->left = nullptr;
                break;
            }
        }
        p = &head;
        head.right = q = head.left;
        while(q){
            if( q->val < R ){ p = q; q = q->right; }
            else if( R < q->val ){ p->right = q->left; q->left = nullptr; delSubtree(q); q = p->right; }
            else{
                delSubtree( q->right ); q->right = nullptr;
                break;
            }
        }
        root = head.right;
        head.left = head.right = nullptr;
        p = q = nullptr;
        return root;
    }
    void delSubtree( TreeNode *root ){
        if ( !root ) return;
        stack<TreeNode *> stk;
        stk.push( root );
        TreeNode * temp = nullptr;
        while(!stk.empty()) {
            bool has_leaf = false;
            temp = stk.top();
            if( temp->left ){
                has_leaf = true; stk.push( temp->left ); temp->left = nullptr;
            }
            if( temp->right ){
                has_leaf = true; stk.push( temp->right ); temp->right = nullptr;
            }
            if( ! has_leaf ){
                stk.pop();
                delete temp; temp = nullptr;
            }
        }
    }
};





int main(int argc, char const *argv[]){
    TreeNode * root = new TreeNode(1);
    root->right = new TreeNode(2);
    prt_nodes( root );
    cout << endl;

    Solution sol;
    root = sol.trimBST( root, 2, 4 );
    prt_nodes( root );

    return 0;
}
