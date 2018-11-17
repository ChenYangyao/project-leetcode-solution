#include "BinaryTree.h"
using namespace std;

typedef MYDS::BinaryTreeNode<int> TreeNode;


/**
 * solution by recursion
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        int total_tilt = 0;
        findTilt(root, total_tilt);
        return total_tilt;
    }
    int findTilt(TreeNode* root, int &total_tilt){
        if( !root ) return 0;
        int sum_l = findTilt(root->left, total_tilt),
            sum_r = findTilt(root->right, total_tilt);
        total_tilt += abs(sum_l - sum_r);
        return sum_l + sum_r + root->val;
    }
};

class Solution2 {
public:
    int findTilt(TreeNode* root) {
        stack<tuple<TreeNode *, int, int, int *>> stk;
        if( root ) stk.emplace(root, INT_MIN, INT_MIN, nullptr );
        int total_tilt = 0;
        while( !stk.empty() ){
            auto & top = stk.top();
            if( get<0>(top) == nullptr ) *get<3>(top) = 0;
            else if( get<1>(top) == INT_MIN ){
                stk.emplace(  get<0>(top)->right, INT_MIN, INT_MIN, &get<2>(top) );
                stk.emplace(  get<0>(top)->left, INT_MIN, INT_MIN, &get<1>(top) );
                continue;
            }else{
                total_tilt += abs( get<1>(top) - get<2>(top) );
                if( get<3>(top) ) *get<3>(top) = get<1>(top) + get<2>(top) + get<0>(top)->val;
            }
            stk.pop();
        }
        return total_tilt;
    }

};


int main(int argc, char const *argv[]){

    Solution sol;
    Solution2 sol2;

    // a self-made test example
    vector<int> v = {1,2,3,-1,5,6,7};
    MYDS::BinaryTree<int> btr(v, -1);
    cout << btr;
    cout << "tilt: " << sol.findTilt( btr.root() ) << endl;
    cout << "tilt: " << sol2.findTilt( btr.root() ) << endl;

    // tests from Leetcode website
    v = {1,2,3};
    btr = MYDS::BinaryTree<int>( v, -1 );
    cout << btr;
    cout << "tilt: " << sol.findTilt( btr.root() ) << endl;
    cout << "tilt: " << sol2.findTilt( btr.root() ) << endl;

    v = {-8,3,0,-8,-100,-100,-100,-100,-1,-100,8};
    btr = MYDS::BinaryTree<int>( v, -100 );
    cout << btr;
    cout << "tilt: " << sol.findTilt( btr.root() ) << endl;
    cout << "tilt: " << sol2.findTilt( btr.root() ) << endl;

    return 0;
}
