#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( !t1 ){ return t2; }
        if( !t2 ){ return t1; }
        t1->val += t2->val;
        _mergeTrees( t1,t2 );
        return t1;
    }
    void _mergeTrees(TreeNode *t1, TreeNode* t2) {
        if( t1->left ){
            if( t2->left ){ t1->left->val += t2->left->val; _mergeTrees( t1->left, t2->left ); }
        }else if( t2->left ){
            std::swap( t1->left, t2->left );
        }
        if( t1->right ){
            if( t2->right ){ t1->right->val += t2->right->val; _mergeTrees( t1->right, t2->right ); }
        }else if( t2->right ){
            std::swap( t1->right, t2->right );
        }
    }
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( !t1 ){ return t2; }
        if( !t2 ){ return t1; }
        t1->val += t2->val;
        std::queue<std::pair<TreeNode *, TreeNode *> > q;
        q.emplace( t1, t2 );
        TreeNode *temp1 = nullptr, *temp2=nullptr;
        while( !q.empty() ){
            temp1 = q.front().first; temp2 = q.front().second;
            q.pop();
            if( temp2->left ){
                if( temp1->left ){
                    temp1->left->val += temp2->left->val; q.emplace( temp1->left, temp2->left );
                }else{
                    std::swap( temp1->left, temp2->left );
                }
            }
            if( temp2->right ){
                if( temp1->right ){
                    temp1->right->val += temp2->right->val; q.emplace( temp1->right, temp2->right );
                }else{
                    std::swap( temp1->right, temp2->right );
                }
            }
        }
        return t1;
    }
};


int main(int argc, char const *argv[]){
    std::vector<TreeNode> t1, t2;
    t1.emplace_back(1);
    t1.emplace_back(3);
    t1.emplace_back(2);
    t1.emplace_back(5);
    t1[0].left = &t1[1];
    t1[0].right = &t1[2];
    t1[1].left = &t1[3];

    t2.emplace_back(2);
    t2.emplace_back(1);
    t2.emplace_back(3);
    t2.emplace_back(4);
    t2.emplace_back(7);
    t2[0].left = &t2[1];
    t2[0].right = &t2[2];
    t2[1].right = &t2[3];
    t2[2].right = &t2[4];

    Solution sol;
    auto * p = sol.mergeTrees( t1.data(), t2.data() );

    std::queue<TreeNode *> q;
    q.push( p );
    while( !q.empty() ){
        cout << q.front()->val << endl;
        if( q.front()->left ){
            q.push( q.front()->left );
        }
        if( q.front()->right ){
            q.push( q.front()->right );
        }
        q.pop();
    }
    return 0;
}
