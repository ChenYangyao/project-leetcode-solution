#include <vector>
#include <stack>
#include <utility>
#include <iostream>
#include <algorithm>
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

/*
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<pair<Node*, int> > stk;
        pair<Node*, int> * top = nullptr;
        Node * p = root;
        while( p || !stk.empty() ){
            while( p ){
                stk.emplace( p, 0 );
                p = p->children.size()?p->children[0]:nullptr;
            }
            top = & stk.top();
            if( top->first->children.size() == top->second ){
                res.emplace_back( top->first->val );
                stk.pop();
                p = nullptr;
            }else if( top->first->children.size() == top->second + 1 ){
                ++ top->second;
                p = nullptr;
            }else{
                p = top->first->children[ ++top->second ];
            }
        }

        return res;
    }
};
*/

/*
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if( !root ){ return res; }
        stack<pair<Node*, size_t> > stk;
        stk.emplace( root, 0 );
        pair<Node*, size_t> *top;
        while( ! stk.empty() ){
            top = & stk.top();
            if( top->second < top->first->children.size() ){
                stk.emplace( top->first->children[ top->second++ ], 0 );
            }else{
                res.emplace_back( top->first->val );
                stk.pop();
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        // The reverse of pre-order (right to left) is equivalent to the post-order (left to right)
        vector<int> inv_res;
        if( !root ){ return inv_res; }
        stack<Node *> stk;
        stk.push( root );
        Node *p = nullptr;
        while( !stk.empty() ) {
            p = stk.top(); stk.pop();
            inv_res.push_back( p->val );
            for( auto q: p->children ) stk.push(q);
        }
        return vector<int>( inv_res.crbegin(), inv_res.crend() );
    }
};


int main(int argc, char const *argv[])
{
    vector<Node> nodes(6);
    for (int i = 0; i < 6; ++i){
        nodes[i].val = i+1;
    }
    nodes[0].children = vector<Node *>( { nodes.data() + 2, nodes.data() + 1, nodes.data() + 3 } );
    nodes[2].children = vector<Node *>( { nodes.data() + 4, nodes.data() + 5 } );

    Solution sol;
    auto res = sol.postorder( nodes.data() );
    for( auto i: res ){
        cout << i << endl;
    }

    return 0;
}
