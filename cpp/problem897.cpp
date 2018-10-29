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

// Class: Solution by rotating the tree.
// Description:
//  - NO extra memory cost.
//  - O(n) time cost.
// Creat: Yangyao Chen, 2018/10/29
class Solution2 {
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

// Class: Modified version of previous one, but use a 'threading method' borrowed from threading BST.
// Creat: Yangyao Chen, 2018/10/29
// Description:
//  - space and time cost is similar with previous one in big-O notation, but it is more beautiful in the code-format.
// Reference:
//  - See Problem 538: Convert Bst To Greater Tree. The official solution give an example of in-order traversal
//      with constant memory cost, which is a variant of threading BST.
//  - Here the method is similar to that solution, by we 'fully' thread it without recovery.
class Solution3 {
public:
    TreeNode* increasingBST(TreeNode* root) {
        auto head = TreeNode(0), *pre = &head, *p = root;
        head.right = root;
        while(p){
            if( p->left ){
                auto *q = p->left;
                locatePre(p)->right = p;
                p->left = nullptr;
                pre->right = p = q;
            }else{
                pre = p;
                p = p->right;
            }
        }
        return head.right;
    }
    // Find the progenitor of p (in-order rank).
    TreeNode* locatePre( TreeNode *p ){
        p = p->left;
        while( p->right ) p = p->right;
        return p;
    }
};
