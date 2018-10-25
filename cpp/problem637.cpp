/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        deque<TreeNode *> dq;
        dq.emplace_back( root );
        while( ! dq.empty() ){
            int size = dq.size();
            double sum = 0.;
            for (int i = 0; i < size; ++i){
                sum += dq.front() -> val;
                if( dq.front()->left ) dq.push_back(dq.front()->left );
                if( dq.front()->right ) dq.push_back(dq.front()->right );
                dq.pop_front();
            }
            res.push_back( sum/size );
        }
        return res;
    }
};
