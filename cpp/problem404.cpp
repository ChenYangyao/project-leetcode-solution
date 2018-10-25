
// Class: Solution, iteratively
// Creat: Yangyao Chen, 2018/10/15
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode *> stk;
        while( root || !stk.empty() ){
            while(root) {
                if( root->left && ! root->left->left && ! root->left->right ) sum += root->left->val;
                if( root->right ) stk.push( root->right );
                root = root->left;
            }
            if( !stk.empty() ){
                root = stk.top(); stk.pop();
            }
        }
        return sum;
    }
};


// Class: Solution, recursively
// Creat: Yangyao Chen, 2018/10/15
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if( !root ){ return 0; }
        return sumOfLeftLeaves(root, false);
    }
    int sumOfLeftLeaves(TreeNode* root, bool isleft) {
        if( isleft && !root->left && !root->right ) return root->val;
        else{
            int sum = 0;
            if( root->left ) sum += sumOfLeftLeaves(root->left, true);
            if( root->right ) sum += sumOfLeftLeaves(root->right, false);
            return sum;
        }
    }
};
