/*
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
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        Node *top = nullptr;
        if( root ){ stk.push( root ); }
        while( !stk.empty() ){
            top = stk.top(); stk.pop();
            res.push_back( top->val );
            for( auto p = top->children.crbegin(); p != top->children.crend(); ++p ){
                stk.push( *p );
            }
        }
        return res;
    }
};
