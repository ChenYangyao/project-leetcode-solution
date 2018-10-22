// Class: This is just a in-order-DFS. We implement it iteratively.
// Description:
//  - Time cost: O(n), where n is number of tree nodes.
//  - Space cost: O(log(n))
// Creat: Yangyao Chen, 2018/10/22
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stk;
        int sum_greaters = 0;
        TreeNode *p = root;
        while( p || !stk.empty() ){
            while(p){
                stk.push( p ); p = p->right;
            }
            p = stk.top(); stk.pop();
            p->val += sum_greaters;
            sum_greaters = p->val;
            p = p->left;
        }
        return root;
    }
};

// Class: Similar to above solution, but implemented recursively.
// Creat: Yangyao Chen, 2018/10/22
class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum_greaters = 0;
        convertBST(root, sum_greaters);
        return root;
    }
    void convertBST(TreeNode *root, int &sum_greaters){
        if( !root ) return;
        convertBST(root->right, sum_greaters);
        root->val += sum_greaters;
        sum_greaters = root->val;
        convertBST(root->left, sum_greaters);
    }
};

