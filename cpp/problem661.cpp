class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        auto res = M;
        int ni = M.size(), nj = M[0].size();
        if(nj > 1) add_to( M, 0, 0, res, 0, 1, ni, nj - 1 );
        if(nj > 1) add_to( M, 0, 1, res, 0, 0, ni, nj - 1 );
        if(ni > 1) add_to( M, 0, 0, res, 1, 0, ni - 1, nj );
        if(ni > 1) add_to( M, 1, 0, res, 0, 0, ni - 1, nj );
        if(ni > 1 && nj > 1){ add_to( M, 0, 0, res, 1, 1, ni - 1, nj - 1 );
        add_to( M, 1, 1, res, 0, 0, ni - 1, nj - 1 );
        add_to( M, 0, 1, res, 1, 0, ni - 1, nj - 1 );
        add_to( M, 1, 0, res, 0, 1, ni - 1, nj - 1 ); }
        int size = 4;
        if( ni < 2 || nj < 2 ) size = 2;
        if( ni == 1 && nj == 1 ) size = 1;
        scale_by(res, 0, 0, 1, 1, size);
        if(nj > 1) scale_by(res, 0, nj-1, 1, 1, size);
        if(ni > 1) scale_by(res, ni-1, 0, 1, 1, size);
        if(ni > 1 && nj > 1) scale_by(res, ni-1, nj-1, 1, 1, size);
        size = 6;
        if( ni < 2 || nj < 2 ) size = 3;
        if(nj > 2) scale_by(res, 0, 1, 1, nj-2, size);
        if(ni > 1 && nj > 2) scale_by(res, ni-1, 1, 1, nj-2, size);
        if(ni > 2) scale_by(res, 1, 0, ni - 2, 1, size);
        if(nj > 1 && ni > 2) scale_by(res, 1, nj-1, ni - 2, 1, size);
        if(ni > 2 && nj > 2) scale_by(res, 1, 1, ni - 2, nj - 2, 9);
        return res;
    }
    void add_to( vector<vector<int>>& From, int i1, int j1,
        vector<vector<int>>& To, int i2, int j2, int ni, int nj ){
        for (int i = 0; i < ni; ++i)
            for (int j = 0; j < nj; ++j)
                To[ i2+i ][j2 + j] += From[ i1 + i ][ j1 + j ];
    }
    void scale_by(vector<vector<int>>& Mat, int i1, int j1, int ni, int nj, int v){
        for (int i = 0; i < ni; ++i)
            for (int j = 0; j < nj; ++j)
                Mat[ i1+i ][j1+j] /= v;
    }
};
