/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *new_root = new TreeNode(0), *new_leaf = new_root, *p = root;
        while( p || !stk.empty() ) {
            while( p ){
                stk.push(p); p = p->left;
            }
            p = stk.top(); stk.pop();
            new_leaf->right = new TreeNode( p->val );
            new_leaf = new_leaf->right;
            p = p->right;
        }
        p = new_root->right;
        delete new_root;
        return p;
    }
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *head = new TreeNode(0);
        head->right = root;
        TreeNode *p = head, *q = root, *r = nullptr;
        while( q ){
            if( r = q->left ){
                while(r->right) r = r->right;
                r->right = q;
                p->right = q->left;
                q->left = nullptr;
                q = p->right;
            }else{
                p = q; q = q->right;
            }
        }
        root = head->right;
        delete head;
        return root;
    }
};
