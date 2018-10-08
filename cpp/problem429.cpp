class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        queue< pair<Node*, size_t> > sq;
        pair<Node*, size_t> *front;
        if( root ) sq.emplace( root, 0 );
        while( !sq.empty() ){
            front = &sq.front();
            if( front->second >= res.size() )
                res.emplace_back( vector<int>({ front->first->val }) );
            else
                res.back().push_back( front->first->val );
            for( auto p: front->first->children )
                sq.emplace( p, front->second + 1 );
            sq.pop();
        }
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        deque< Node* > dq;
        if( root ) dq.emplace( root, 0 );
        while( !dq.empty() ){
           size_t size = dq.size();
           res.emplace_back();
           for( size_t i = 0; i < size; ++i ){
                res.back().push_back( dq.front()->val );
                for( auto p: dq.front()->children )
                    dq.push_back( p );
                dq.pop_front();
           }
        }
        return res;
    }
};

