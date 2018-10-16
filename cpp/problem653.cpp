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
    bool findTarget(TreeNode* root, int k) {
        if( !root ) return false;
        stack<TreeNode *> stk; stk.push_back(root);
        TreeNode *temp = nullptr, *find = nullptr;
        while( !stk.empty() ){
            temp = stk.top(); stk.pop();
            if( ( find = locateVal(k - temp->val, root) ) && find != temp ) return true;
            if( temp->left ) stk.push(temp->left);
            if( temp->right ) stk.push(temp->right);
        }
        return false;
    }
    TreeNode * locateVal(int val, TreeNode *p){
        while(p){
            if( val < p->val ) p = p->left;
            else if( p->val < val ) p = p->right;
            else break;
        }
        return p;
    }
};
