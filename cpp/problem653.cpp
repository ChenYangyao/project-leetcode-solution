/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Class: Search each element by BST-search.
 // Description:
 //  - Time cost: O(n*log(n)).
 //  - Space cost: const.
 // Creat: Yangyao Chen, 2018/10/22
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if( !root ) return false;
        stack<TreeNode *> stk; stk.push_back(root);
        TreeNode *temp = nullptr, *find = nullptr;
        while( !stk.empty() ){
            temp = stk.top(); stk.pop();
            if( ( find = locateVal(k - temp->val, root) ) && find != temp ) return true;
            if( temp->left ) stk.push(temp->left);
            if( temp->right ) stk.push(temp->right);
        }
        return false;
    }
    TreeNode * locateVal(int val, TreeNode *p){
        while(p){
            if( val < p->val ) p = p->left;
            else if( p->val < val ) p = p->right;
            else break;
        }
        return p;
    }
};

// Class: treat the BST as a sorted sequence, then narrow the range by increase/decreast the lower index/upper index..
// Description:
//  - Time cost: O(n).
//  - Space cost: O(log(n)).
// Creat: Yangyao Chen, 2018/10/22
class Solution2{
public:
    bool findTarget(TreeNode* root, int k) {
        init(root); rinit(root);
        TreeNode *l = next(), *r = rnext();
        while( l != r ) {
            int sum = l->val + r->val;
            if( sum < k ){ l = next(); }
            else if( sum > k ){ r = rnext(); }
            else{ return true; }
        }
        return false;
    }
protected:
    void init(TreeNode *root){ _cur = root; }
    void rinit(TreeNode *root){ _rcur = root; }
    TreeNode * next(  ){
        if( _cur || !_stk.empty() ){
            TreeNode *p = _cur;
            while( p ){
                _stk.push( p ); p = p->left;
            }
            p = _stk.top(); _stk.pop();
            _cur = p->right;
            return p;
        }
        return nullptr;
    }
    TreeNode * rnext(  ){
        if( _rcur || !_rstk.empty() ){
            TreeNode *p = _rcur;
            while( p ){
                _rstk.push( p ); p = p->right;
            }
            p = _rstk.top(); _rstk.pop();
            _rcur = p->left;
            return p;
        }
        return nullptr;
    }
    TreeNode *_cur = nullptr, *_rcur = nullptr;
    stack<TreeNode *> _stk, _rstk;
};
