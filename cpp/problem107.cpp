#include "mystd.h"
#include "BinaryTree.h"
using namespace std;
using namespace MYSTD;
typedef MYDS::BinaryTreeNode<int> TreeNode;

/**
 * simply apply BFS and then reverse the result
 *
 * Thanks for the moving paradigm in C++, the swap() operation
 * in reverse() has constant performance. Otherwise in an language
 * that always performs deep-copy, you may need to consider the
 * complexity in reverse.
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        levelOrder(root, res);
        reverse( res.begin(), res.end() );
        return res;
    }
    void levelOrder(TreeNode *root, vector<vector<int> > &res){
        queue< TreeNode *> sq;cout << res.size() << endl;
        if( root ) sq.emplace(root);
        while( !sq.empty() ){
            res.emplace_back();
            int sz = sq.size();
            for (int i = 0; i < sz; ++i){
                auto &front = sq.front();
                res.back().push_back(front->val);
                if( front->left ) sq.emplace(front->left);
                if( front->right ) sq.emplace(front->right);
                sq.pop();
            }
        }
    }
};

int main(int argc, char const *argv[]){
    // test by the example in Leetcode problem
    vector<int> v = {3,9,20,-1,-1,15,7};
    MYDS::BinaryTree<int> tr(v, -1);
    Solution sol;
    auto res = sol.levelOrderBottom( tr.root() );
    for(auto & i: res){
        MYFILE::print_range(i) << endl;
    }

    return 0;
}
