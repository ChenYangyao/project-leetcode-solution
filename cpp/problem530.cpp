class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = root->left ? (root->val - root->left->val) : (root->right->val - root->val);
        // Note than you can not set this to be INT_MIN, which is unsafe when you use a positive number x to minus it: x - INT_MIN
        // Also, the setting here is valid only if all nodes are positive.
        int tempVal = -minDiff;
        stack<TreeNode*> stk;
        while( root || !stk.empty() ){
            while(root) {
                stk.push(root); root = root->left;
            }
            root = stk.top(); stk.pop();
            if( root->val - tempVal < minDiff ) minDiff = root->val - tempVal;
            tempVal = root->val;
            root = root->right;
        }
        return minDiff;
    }
};
