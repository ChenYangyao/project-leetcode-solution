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
// Description:
//  - Time cost: O(n), where n is number of tree nodes.
//  - Space cost: O(log(n))
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

// Class: Solution by threaded BST
// Creat: Yangyao Chen, 2018/10/29
// References: Leetcode official solution. Thanks Ziyang for recommending.
class Solution3 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        auto *p = root;
        while(p){
            if( p->right ){
                auto *pre = locatePre(p, p);
                if( pre->left ){
                    pre->left = nullptr;
                }else{
                    pre->left = p;
                    p = p->right;
                    continue;
                }
            }
            sum += p->val; p->val = sum;
            p = p->left;
        }
        return root;
    }
    TreeNode* locatePre( TreeNode *p, TreeNode *root ){
        p = p->right;
        while( p->left && p->left != root ) p = p->left;
        return p;
    }
};
