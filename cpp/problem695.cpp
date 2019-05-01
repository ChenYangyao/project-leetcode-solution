#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <algorithm>
#include <ctime>
using namespace std;

// Class: Solution by 2-d Union-Find Set (UFSet thereafter).
// Description:
//  - Here we use matrix element 0 to represent the sea, use 1 to represent the island.
//  - Positive number holded by root element represents the number of elements in the connected component.
//  - Negative number holded by non-root element represent the index of the parent element in the tree.
//        The 2-d index and 1-d index (negative) can be converted using id2coord() and coord2id().
//  - linear time cost. As tested below, this is also faster than the DFS methods done either by recursion or iteration.
//  - CONSTANT space cost. This is the most important merit of the UFSet.
// Creat: Yangyao, date 20181006
// References: none.
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        _grid = &grid;
        nrow = grid.size(); ncol = grid[0].size();
        for (int i = 0; i < nrow; ++i){
            for (int j = 0; j < ncol; ++j){
                if( !grid[i][j] ) continue;
                // Note that each eage is considered only once. So only the upper and left element are checked.
                int up = i?findRoot(i-1,j):0;
                int left = j?findRoot(i,j-1):0;
                if( up ){
                    // We merge the current element to the tree containing the upper element.
                    grid[i][j] = up; getVal(up) += 1;
                    // If the left element and upper element belong to different tree, we merge them.
                    if( left && left != up ) merge( left, up );
                }else if( left ){
                    // If no upper island, we merge the current element to the tree containing the left element.
                    grid[i][j] = left; getVal(left) += 1;
                }
            }
        }
        int max_area = 0;
        for(const auto & row: grid){
            for(const auto & i: row){
                if( i > max_area ) max_area = i;
            }
        }
        return max_area;
    }
private:
    int ncol, nrow;
    vector<vector<int> > *_grid;

    // Func: conversion between 1-d and 2-d index
    void id2coord(int id, int &x, int &y){
        x = (-id - 1)/ncol; y = (-id - 1)%ncol;
    }
    int coord2id(int x, int y){
        return -(x*ncol + y + 1);
    }
    int &getVal(int id){
        int x,y;
        id2coord(id,x,y);
        return (*_grid)[x][y];
    }
    // Func: find root index of a element.
    int findRoot(int x, int y){
        int temp = (*_grid)[x][y];
        if( temp == 0 ) return 0;
        int x0 = x, y0 = y;
        while(temp < 0) {
            id2coord(temp, x, y);
            temp = (*_grid)[x][y];
        }
        int root = coord2id(x, y);
        temp = (*_grid)[x0][y0];
        while(temp < 0) {
            (*_grid)[x0][y0] = root;
            id2coord(temp,x0,y0);
            temp = (*_grid)[x0][y0];
        }

        return root;
    }
    // Func: Merge the two trees rooted in root1 and root2.
    //   Note that we always merge the small tree to the large one.
    //   This is the optimized choice because it reduces the possible inceasing of tree height.
    void merge(int root1, int root2){
        int &v1 = getVal(root1), &v2 = getVal(root2);
        if( v1 > v2 ){
            v1 += v2; v2 = root1;
        }else{
            v2 += v1; v1 = root2;
        }
    }
};


// Class: Solution by dfs searching, recursively.
// Description:
//  - linear time cost O(ncol*nrow).
//  - linear space cost O(ncol*nrow).
// Creat: Yangyao, date 20181006
// References: motivated by leetcode user solution.
class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int> > &grid) {
        nrow = grid.size(); ncol = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < nrow; ++i){
            for (int j = 0; j < ncol; ++j){
                max_area = max( max_area, dfs( grid, i, j ) );
            }

        }
        return max_area;
    }
    int dfs( vector<vector<int> > &grid, int i, int j ){
        if( ! grid[i][j] ) return 0;
        grid[i][j] = 0;
        int res = 1;
        if( i ) res += dfs( grid, i-1, j );
        if( i + 1 < nrow ) res += dfs( grid, i+1, j );
        if( j ) res += dfs( grid, i, j-1 );
        if( j + 1 < ncol ) res += dfs(grid, i, j+1);
        return res;
    }
private:
    int nrow, ncol;
};


// Class: Solution by dfs searching, iteratively.
// Description:
//  - linear time cost O(ncol*nrow).
//  - linear space cost O(ncol*nrow).
// Creat: Yangyao, date 20181006
// References: motivated by leetcode user solution.
class Solution3 {
public:
    int maxAreaOfIsland(vector<vector<int> > &grid) {
        nrow = grid.size(); ncol = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < nrow; ++i){
            for (int j = 0; j < ncol; ++j){
                max_area = max( max_area, dfs( grid, i, j ) );
            }
        }
        return max_area;
    }
    int dfs( vector<vector<int> > &grid, int i, int j ){
        if( !grid[i][j] ) return 0;
        int area = 0;
        stack<int> stk;
        stk.push( i*ncol + j );
        while( !stk.empty() ){
            int id = stk.top(); stk.pop();
            i = id / ncol; j = id % ncol;
            if( ! grid[i][j] ) continue;
            area += 1; grid[i][j] = 0;
            if( i && grid[i-1][j] ) stk.push( (i-1)*ncol+j );
            if( i + 1 < nrow && grid[i+1][j] ) stk.push( (i+1)*ncol+j );
            if( j && grid[i][j-1] ) stk.push( i*ncol+j-1 );
            if( j+1 < ncol && grid[i][j+1] ) stk.push( i*ncol+j+1 );
        }
        return area;
    }
private:
    int nrow, ncol;
};

// Func: generate a random matrix
// @ - [nrow, ncol] size of the matrix to be generated
// % - [matrix] random matrix
vector<vector<int> > getRandomMat(int nrow, int ncol){
    vector<vector<int> > res(nrow, vector<int>(ncol) );
    default_random_engine e;
    uniform_int_distribution<int> u(0,1);
    for (int i = 0; i < nrow; ++i){
        for (int j = 0; j < ncol; ++j){
            res[i][j] = u(e);
        }
    }
    return res;
}

// Func: repeat the solution, return the time cost.
// @ - [sol] instance of solution class.
//   - [grid] grid to find max area.
//   - [repeat] times to repeat.
// % - [double] time cost in second.
template<typename T>
double checkTime( T &sol, vector<vector<int> > &grid, int repeat = 100 ){
    clock_t tot_t = 0;
    vector<vector<int> > _grid;
    for (int i = 0; i < repeat; ++i){
        _grid = grid;
        auto t1 = clock();
        sol.maxAreaOfIsland( _grid );
        auto t2 = clock();
        tot_t += t2 - t1;
    }
    return double(tot_t)/CLOCKS_PER_SEC;
}

// Func: Driver function to test solutions
int main(int argc, char const *argv[]){
    Solution sol; Solution2 sol2; Solution3 sol3;
    vector<vector<int> > grid, _grid;

    grid = getRandomMat(5,5);
    // Check the results by different methods.
    // Method by UFSet
    _grid = grid;
    cout << "result by method 1: " << sol.maxAreaOfIsland( _grid ) << endl;
    // You may be interested in the 2-d UFSet
    cout << "grid matrix after UFSet operation:\n";
    for(const auto & row: _grid){
        for(const auto & i: row){
            cout << i << '\t';
        }
        cout << endl;
    }
    // DFS method, recursively
    _grid = grid;
    cout << "result by method 2: "  << sol2.maxAreaOfIsland( _grid ) << endl;
    // DFS method, iteratively
    _grid = grid;
    cout << "result by method 3: "  << sol3.maxAreaOfIsland( _grid ) << endl;

    // Here we generate a large matrix to test the performance of the three methods.
    grid = getRandomMat(1000, 1000);
    cout << "time of method 1: " << checkTime(sol, grid) << endl;
    cout << "time of method 2: " << checkTime(sol2, grid) << endl;
    cout << "time of method 3: " << checkTime(sol3, grid) << endl;

    return 0;
}

