// Class: Iteratively, DFS
// Creat: Yangyao Chen, 2018/10/26
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > paths;

        stack<pair<int, bool>> stk; stk.emplace(0, true);
        vector<int> path;
        int last = graph.size() - 1;
        while( !stk.empty() ){
            auto &top = stk.top();
            if( top.second ){
                path.push_back( top.first );
                if( top.first == last ){
                    paths.emplace_back( path );
                }else{
                    top.second = false;
                    for(auto i: graph[ top.first ]) stk.emplace( i, true );
                    continue;
                }
            }
            stk.pop(); path.pop_back();
        }

        return paths;
    }
};

// Class: Recursively, DFS
// Creat: Yangyao Chen, 2018/10/26
class Solution2 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;
        vector<int> path;
        allPathsSourceTarget( graph, 0, graph.size()-1, res, path  );
        return res;
    }
    // Func: Find the path from node 'b' to 'e', in the 'graph', joining with the previous 'path', and append it to result 'res'.
    // @ - [graph] graphics to work with.
    //     [b,e] path beginning and end.
    //     [res] result paths.
    //     [path] 'previous path', from node '0' to node 'b'.
    // Note: this is a DFS algorithm.
    void allPathsSourceTarget( vector<vector<int>>& graph, int b, int e, vector<vector<int> > &res, vector<int> &path ){
        if( b == e ){
            res.emplace_back( path ); res.back().push_back(b);
        }else{
            path.push_back(b);
            for(auto i: graph[b]){
                allPathsSourceTarget(graph, i, e, res, path);
            }
            path.pop_back();
        }
    }
};


