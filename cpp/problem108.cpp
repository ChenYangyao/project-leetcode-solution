/**
 * solution by the DFS, recursively
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.empty() ) return nullptr;
        return sortedArrayToBST( 0, nums.size(), nums );
    }
    TreeNode* sortedArrayToBST(int b, int e, vector<int>& nums){
        int cid = b + (e-b)/2;
        TreeNode *p = new TreeNode(nums[cid]);
        if( cid != b ) p->left = sortedArrayToBST(b,cid,nums);
        if( cid +1 != e ) p->right = sortedArrayToBST(cid+1,e,nums);
        return p;
    }
};


/**
 * solution by the DFS, but implemented by a stack
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.empty() ) return nullptr;
        TreeNode head(0);
        stack<tuple<int,int,TreeNode*&> > stk;
        stk.emplace( 0, nums.size(), head.right );

        int b,e,cid;
        TreeNode *p = nullptr;
        while( !stk.empty() ){
            b = get<0>(stk.top());
            e = get<1>(stk.top());
            TreeNode *& parent = get<2>(stk.top());
            stk.pop();
            cid = b + (e-b)/2;
            p = new TreeNode(nums[cid]);
            parent = p;
            if( cid != b ) stk.emplace( b,cid,p->left );
            if( cid +1 != e ) stk.emplace( cid+1,e,p->right );
        }
        return head.right;
    }

};
