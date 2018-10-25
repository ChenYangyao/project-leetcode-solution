#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int nx = A.size(), ny = A[0].size();
        vector<vector<int> > res( ny, vector<int>(nx, 0) );
        for (int i = 0; i < nx; ++i)
            for (int j = 0; j < ny; ++j){
                res[j][i] = A[i][j];
            }
        return res;
    }
};
