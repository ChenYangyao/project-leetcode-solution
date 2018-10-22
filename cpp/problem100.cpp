class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p && q ){
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else if( p || q ){
            return false;
        }else{
            return true;
        }
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1, stk2;
        if( p ) stk1.push(p);
        if( q ) stk2.push(q);

        while( !stk1.empty() ){
            if( stk2.empty() ) return false;
            p = stk1.top(); stk1.pop();
            q = stk2.top(); stk2.pop();
            if( p->val != q->val ) return false;
            if( p->right ){
                if( q->right ){
                    stk1.push(p->right); stk2.push(q->right);
                }else
                    return false;
            }else if( q->right ) return false;

            if( p->left ){
                if( q->left ){
                    stk1.push(p->left); stk2.push(q->left);
                }else
                    return false;
            }else if(q->left) return false;
        }
        return stk2.empty()? true: false;
    }
};
