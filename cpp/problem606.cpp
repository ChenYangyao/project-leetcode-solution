#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    string tree2str(TreeNode *t) {
        string s;
        if(t) tree2str(t, s);
        return s;
    }
    void tree2str(TreeNode *t, string &s){
        s += to_string(t->val);
        if( t->left ){
            formEnclosed(t->left, s);
            if( t->right ) formEnclosed(t->right, s);
        }else if(t->right){
            s += "()";
            formEnclosed(t->right, s);
        }
    }
    void formEnclosed(TreeNode *t, string &s){
        s += '('; tree2str(t, s); s+= ')';
    }
};



class Solution2 {
public:
    string tree2str(TreeNode *t) {
        string s;
        stack<pair<TreeNode *, int> > stk;
        TreeNode *p = t;
        while( p || !stk.empty() ){
            while(p) {
                s += to_string( p->val );
                if( p->left || p->right ){ s += '('; }
                stk.emplace( p, 0 );
                p = p->left;
            }
            p = stk.top().first;
            if( stk.top().second ){
                if( p->right ) s += ')';
                stk.pop(); p = nullptr;
            }else{
                if( p->right ){
                    s += ")(";
                    stk.top().second = 1;
                    p = p->right;
                }else if( p->left ){
                    s += ')';
                    stk.pop(); p = nullptr;
                }else{
                    stk.pop(); p = nullptr;
                }
            }
        }
        return s;
    }
};



int main(int argc, char const *argv[])
{
    vector<TreeNode> nds;
    for(int i = 0; i < 4; ++i){
        nds.emplace_back(i);
    }
    nds[0].left = nds.data() + 1; nds[0].right = nds.data() + 2;
    nds[1].left = nds.data() + 3;

    Solution2 sol;
    auto s = sol.tree2str(nds.data());
    cout << s << endl;


    return 0;
}
