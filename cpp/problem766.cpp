class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        for (int i = 0; i < nrow - 1; ++i){
            int ip1 = i+1;
            for (int j = 0; j < ncol - 1; ++j){
                if( matrix[i][j] != matrix[ip1][j+1] ) return false;
            }
        }
        return true;
    }
};
