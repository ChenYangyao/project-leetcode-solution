// Class: Invert the tree by pre-order visit.
//  - time cost: Theta(number of tree nodes).
//  - no extra space occupation.
// Creat: Yangyao Chen, date 20191007
// References: none.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if( !root ) return nullptr;
        stack<TreeNode *> stk;
        stk.emplace(root);
        TreeNode *temp;
        while( !stk.empty() ){
            temp = stk.top(); stk.pop();
            swap( temp->left, temp->right );
            if( temp->right ) stk.emplace( temp->right );
            if( temp->left ) stk.emplace( temp->left );
        }
        return root;
    }
};
