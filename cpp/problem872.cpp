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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        findLeaves( root1, leaves1 );
        findLeaves( root2, leaves2 );
        if( leaves1.size() != leaves2.size() ) return false;
        for (size_t i = 0; i < leaves1.size(); ++i){
            if( leaves1[i] != leaves2[i] ) return false;
        }
        return true;
    }
    void findLeaves(TreeNode *root, vector<int> & leaves){
        bool is_leaf = true;
        if( root->left ){
            is_leaf = false;
            findLeaves(root->left, leaves);
        }
        if( root->right ){
            is_leaf = false;
            findLeaves(root->right, leaves);
        }
        if( is_leaf ) leaves.emplace_back( root->val );
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        findLeaves( root1, leaves1 );
        findLeaves( root2, leaves2 );
        if( leaves1.size() != leaves2.size() ) return false;
        for (size_t i = 0; i < leaves1.size(); ++i){
            if( leaves1[i] != leaves2[i] ) return false;
        }
        return true;
    }
    void findLeaves(TreeNode *root, vector<int> & leaves){
        stack<TreeNode*> stk;
        stk.push( root );
        TreeNode * temp = nullptr;
        bool has_leaf = false;
        while(!stk.empty()) {
            temp = stk.top(); stk.pop();
            has_leaf = false;
            if( temp->right ){ has_leaf = true; stk.push( temp->right ); }
            if( temp->left ){ has_leaf = true; stk.push( temp->left ); }
            if( !has_leaf ){ leaves.push_back( temp->val ); }
        }
    }
};
