#include "mystd.h"
#include "my_random.h"
#include "mytime.h"
#include "myfile.h"
using namespace MYSTD;
using namespace std;

// Class: Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


// Class: Solution by DPS-like algorithm, with iteration. Top-Down method.
// Description:
//  - Time complexity O(N*log(N)), where N is number of elements of the grid.
//  - Space cost: log(N) for the DFS stack.
// Creat: Yangyao Chen, 2028/10/18
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node *head = new Node(true,true,nullptr, nullptr, nullptr, nullptr);
        stack<tuple<int,int,int, Node*> > subgrids;
        subgrids.emplace( 0,0,grid.size(), head );

        while( !subgrids.empty() ){
            auto &top = subgrids.top();
            int ox = get<0>( top ), oy = get<1>( top ), size = get<2>( top );
            auto *parent = get<3>( top);
            subgrids.pop();
            if( toSplit(ox,oy,size,grid) ){
                parent->isLeaf = false;
                parent->topLeft = new Node( true, true, nullptr, nullptr, nullptr, nullptr );
                subgrids.emplace(ox,oy,size/2,parent->topLeft);
                parent->topRight = new Node( true, true, nullptr, nullptr, nullptr, nullptr );
                subgrids.emplace(ox,oy+size/2,size/2,parent->topRight);
                parent->bottomLeft = new Node( true, true, nullptr, nullptr, nullptr, nullptr );
                subgrids.emplace(ox+size/2,oy,size/2,parent->bottomLeft);
                parent->bottomRight = new Node( true, true, nullptr, nullptr, nullptr, nullptr );
                subgrids.emplace(ox+size/2,oy+size/2,size/2,parent->bottomRight);
            }else{
                parent->isLeaf = true;
                parent->val = grid[ox][oy];
            }
        }

        return head;
    }
    bool toSplit(int ox, int oy, int size, vector<vector<int> > &grid){
        int tag = grid[ox][oy];
        for (int i = ox; i < ox+size; ++i){
            for (int j = oy; j < oy+size; ++j){
                if( grid[i][j] != tag ) return true;
            }
        }
        return false;
    }
};

// Class: Solution with merge-like algorithm. Bottom-up method.
// Description:
//  - The basic idea is to reuse the input grid, to keep the node information.
//  - Time cost: O(N), where N is number of elements of the grid.
//  - No extra space cost.
// Creat: Yangyao, 2018/10/18
class Solution2 {
public:
    Node* construct(vector<vector<int>>& grid){
        initBottom(grid);
        int n = grid.size(), step = 2;
        while( step <= n/2 ) {
            for (int i = 0; i < n; i+=step*2)
            for (int j = 0; j < n; j+=step*2){
                if( !( grid[i][j] && grid[i][j+step] && grid[i+step][j] && grid[i+step][j+step] &&
                    grid[i][j+1] == grid[i][j+step+1] && grid[i][j+1] == grid[i+step][j+1] &&
                    grid[i][j+1] == grid[i+step][j+step+1] ) )
                {
                    *(Node **)( & grid[i+1][j] ) = new Node(
                        true,false, newLeaf(i,j,grid), newLeaf(i,j+step,grid), newLeaf(i+step,j, grid), newLeaf(i+step,j+step,grid)
                    );
                    grid[i][j] = false;
                }
            }
            step *= 2;
        }
        return grid[0][0]?newLeaf(grid[0][1]):( *(Node**)(&grid[1][0]) );
    }
    void initBottom(vector<vector<int>>& grid){
        int n = grid.size();
        for (int i = 0; i < n; i += 2)
        for (int j = 0; j < n; j += 2){
            if( (grid[i][j] == grid[i+1][j]) && ( grid[i][j] == grid[i][j+1]) && ( grid[i][j] == grid[i+1][j+1] ) ){
                grid[i][j] = true;
            }else{
                *(Node **)( & grid[i+1][j] ) = new Node(
                    true,false,newLeaf(grid[i][j]),newLeaf(grid[i][j+1]),newLeaf(grid[i+1][j]),newLeaf(grid[i+1][j+1])
                );
                grid[i][j] = false;
            }
        }
    }
    static Node *newLeaf(int val){
        return new Node( val, true, nullptr, nullptr, nullptr, nullptr );
    }
    static Node *newLeaf(int i, int j, vector<vector<int> > &grid){
        return grid[i][j]?newLeaf(grid[i][j+1]):( *(Node **)( &grid[i+1][j] ) );
    }
};

// Class: DFS-like solution, recursive. Top-down method.
// This is COPIED from the Leetcode user solution, just for time testting.
class Solution3 {
public:
    Node* construct(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return NULL;
        return helper(grid, 0, grid.size(), 0, grid.size());
    }
    Node *helper(vector<vector<int>> &grid, int r_start, int r_end, int c_start, int c_end){
        bool val = grid[r_start][c_start];
        for(int i = r_start; i<r_end; i++){
            for(int j = c_start; j<c_end; j++){
                if(grid[i][j] != val){
                    Node *node = new Node(true, false, NULL, NULL, NULL, NULL);
                    node->topLeft = helper(grid, r_start, r_start + (r_end-r_start)/2, c_start, c_start + (c_end-c_start)/2);
                    node->topRight = helper(grid, r_start, r_start + (r_end-r_start)/2, c_start + (c_end-c_start)/2, c_end);
                    node->bottomLeft = helper(grid, r_start + (r_end-r_start)/2, r_end, c_start, c_start + (c_end-c_start)/2);
                    node->bottomRight = helper(grid, r_start + (r_end-r_start)/2, r_end, c_start + (c_end-c_start)/2, c_end);
                    return node;
                }
            }
        }
        return new Node(val, true, NULL, NULL, NULL, NULL);
    }
};

// Func: Generate the random nxn matrix, using random number generator r.
vector<vector<int> > randomGrid(int n, MYMATH::RandomsInt<int> & r){
    vector<vector<int> > grid = vector<vector<int> >( size_t(1) << n );
    for( auto & row: grid ) r.get( row, size_t(1) << n );
    return grid;
}
// Func: Destroy the tree, release attached memory.
void delTree(Node * &p){
    if(p){
        delTree(p->topLeft); delTree(p->topRight); delTree(p->bottomLeft); delTree(p->bottomRight);
        delete p;
        p = nullptr;
    }
}
// Func: Test solution time, for nxn matrix, repeat 100 times.
template<typename T>
double timer( T sol, int n, int repeat = 100 ){
    MYMATH::RandomsInt<int> r(0,1);
    clock_t t1 = 0, t_tot = 0;
    for (int i = 0; i < repeat; ++i){
        auto grid = randomGrid(n,r);
        t1 = clock();
        auto *p = sol.construct( grid );
        t_tot += clock() - t1;
        delTree(p);
    }
    return double(t_tot)/CLOCKS_PER_SEC;
}


int main(int argc, char const *argv[]){
    Solution sol; Solution2 sol2; Solution3 sol3;

    int matsize, repeat;
    MYFILE::width_prt(cout, {10,10,10,10,10}, ' ', "MatSize", "Repeat" ,"TopDown", "BottomUp", "Recursion") << endl;
    matsize = 5; repeat = 1000;
    MYFILE::width_prt(cout, {10,10,10,10,10}, ' ', matsize, repeat, timer( sol, matsize, repeat ), timer( sol3, matsize, repeat ),timer( sol2, matsize, repeat )) << endl;
    matsize = 7; repeat = 100;
    MYFILE::width_prt(cout, {10,10,10,10,10}, ' ', matsize, repeat, timer( sol, matsize, repeat ), timer( sol3, matsize, repeat ),timer( sol2, matsize, repeat )) << endl;
    matsize = 9; repeat = 10;
    MYFILE::width_prt(cout, {10,10,10,10,10}, ' ', matsize, repeat, timer( sol, matsize, repeat ), timer( sol3, matsize, repeat ),timer( sol2, matsize, repeat )) << endl;

    return 0;
}
