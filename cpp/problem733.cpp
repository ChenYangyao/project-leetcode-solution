#include "mystd.h"
#include "myfile.h"
#include <utility>
using namespace MYSTD;
using namespace std;

// Class: Solution by DFS, recursively. This could not avoid the worst case
//      where the stack can take ~n/2 space (n is numRow x numCol of input matrix).
// Creat: Yangyao, 20181024
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if( image[sr][sc] == newColor ) return image;
        floodFill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    void floodFill(vector<vector<int> > &image, int sr, int sc, int newColor, int oldColor){
        image[sr][sc] = newColor;
        if( sr && image[sr-1][sc] == oldColor ) floodFill(image, sr-1,sc,newColor,oldColor);
        if( sr + 1 < int(image.size()) && image[sr+1][sc] == oldColor ) floodFill(image, sr + 1,sc,newColor,oldColor);
        if( sc && image[sr][sc-1] == oldColor ) floodFill(image, sr,sc-1,newColor,oldColor);
        if( sc + 1 < int(image[0].size()) && image[sr][sc+1] == oldColor ) floodFill(image, sr,sc+1,newColor,oldColor);
    }
};


// Class: Solution by DFS, iteratively. This also could not avoid the worst case
//      where the stack can take ~n/2 space (n is numRow x numCol of input matrix).
// Creat: Yangyao, 20181024
class Solution2 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if( image[sr][sc] == newColor ) return image;
        int nr = image.size(), nc = image[0].size(), oldColor = image[sr][sc];
        stack<pair<int,int> > stk;
        stk.emplace( sr, sc );
        while(!stk.empty()){
            sr = stk.top().first; sc = stk.top().second; stk.pop();
            image[sr][sc] = newColor;
            if( sr && image[sr-1][sc] == oldColor ) stk.emplace( sr-1,sc );
            if( sr + 1 < nr && image[sr+1][sc] == oldColor ) stk.emplace( sr+1,sc );
            if( sc && image[sr][sc-1] == oldColor ) stk.emplace( sr,sc-1 );
            if( sc + 1 < nc && image[sr][sc+1] == oldColor ) stk.emplace( sr,sc+1 );
        }
        return image;
    }
};

// Class: The solution use UFSet. This can avoid the worst case, since it consumes NO extra memory.
//      But this will be less efficient if the filled area is small.
// Creat: Yangyao Chen, 2018/10/24
class Solution3 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        img = &image; nr = image.size(); nc = image[0].size();
        int oldColor = image[sr][sc];
        if( oldColor == newColor ) return image;
        for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j){
            if( image[i][j] != oldColor ) continue;
            int up = (i && ( image[i-1][j] < 0 || image[i-1][j] == oldColor) )?findRoot(i-1,j):0;
            int left = (j && ( image[i][j-1] < 0 || image[i][j-1] == oldColor) )?findRoot(i,j-1):0;
            if( up ){
                image[i][j] = up;
                if( left && left != up ) mergeRoot(left,up);
            }else if( left ){
                image[i][j] = left;
            }
        }
        for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j){
            if( image[i][j] < 0 ) image[i][j] = findRoot(i,j);
        }
        int rootToBeFilled = findRoot(sr, sc);
        for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j){
            if( (image[i][j] < 0 || image[i][j] == oldColor) && findRoot(i,j) == rootToBeFilled ) image[i][j] = newColor;
            else if( image[i][j] < 0 ) image[i][j] = oldColor;
        }
        return image;
    }
protected:
    vector<vector<int>> *img = nullptr;
    int nr = 0, nc = 0;

    int coord2id(int i, int j){ return -(i*nc + j+1); }
    void id2coord(int id, int &i, int &j){ int temp = -id-1; i = temp/nc; j = temp%nc; }
    int findRoot(int i, int j){
        int i0 = i, j0 = j, val = (*img)[i0][j0];

        while( val < 0 ){
            id2coord(val,i,j);
            val = (*img)[i][j];
            if( val < 0 ) (*img)[i0][j0] = val;
            i0 = i; j0 = j;
        }
        return coord2id(i,j);
    }
    void mergeRoot(int id1, int id2){
        int i,j;
        id2coord(id1, i, j);
        (*img)[i][j] = id2;
    }
};


int main(int argc, char const *argv[])
{

    vector<vector<int> > image = {{0,0,1},{1,1,1}};
    Solution3 sol;
    auto filled_image =  sol.floodFill(image, 1, 0, 2);
    for(auto & i: filled_image){
        MYFILE::print_range(i) << endl;
    }cout << endl;
    return 0;
}

