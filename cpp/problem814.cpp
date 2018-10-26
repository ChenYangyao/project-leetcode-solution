// Class: Recursively, post-order
// Creat: Yangyao Chen, 2018/10/26
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        _pruneTree(root);
        return root;
    }
    void _pruneTree(TreeNode* &root) {
        if( !root ) return;
        _pruneTree( root->left );
        _pruneTree( root->right );
        if( !(root->left || root->right || root->val) ){
            delete root;
            root = nullptr;
        }
    }
};

// Class: Iteratively, post-order
// Creat: Yangyao Chen, 2018/10/26
class Solution2 {
public:
    TreeNode* pruneTree(TreeNode* root) {
        stack<pair<TreeNode *&, bool> > stk;
        if( root ) stk.emplace( root, true );

        while(!stk.empty()) {
            auto &top = stk.top() ;
            if( top.second ){
                if( top.first->left ) stk.emplace( top.first->left, true );
                if( top.first->right ) stk.emplace( top.first->right, true );
                top.second = false;
            }else{
                if( !(top.first->left || top.first->right || top.first->val) ){
                    delete top.first;
                    top.first = nullptr;
                }
                stk.pop();
            }
        }
        return root;
    }
};
