#include <stack>
#include <utility>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if( !root ){ return 0; }
        int depth = 0;
        for( const auto & p: root->children ){
            int branch_depth = maxDepth( p );
            if( branch_depth > depth ) depth = branch_depth;
        }
        return depth + 1;
    }
};


#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if( !root ){ return 0; }
        int max_depth = 0;

        stack< pair<Node*, int> > stk;
        stk.emplace(root, 1);

        int depth = 0;
        Node* node = nullptr;
        while( !stk.empty() ){
            node = stk.top().first;  depth = stk.top().second;
            stk.pop();
            if( depth > max_depth ) max_depth = depth;
            for( auto p: node->children ){
                stk.emplace(p, depth + 1);
            }
        }
        return max_depth;
    }
};
