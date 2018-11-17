#include "mystd.h"
using namespace std;


class Solution {
public:
    vector<vector<int> > largeGroupPositions(string S) {
        vector<vector<int> > res;
        int i = 0, n = S.size(), j = 1;
        for (; j < n; ++j){
            if( S[i] != S[j] ){
                if( j - i >= 3 ){
                    res.push_back( vector<int>({i, j-1}) );
                }
                i = j;
            }
        }
        if( j - i >= 3 ) res.push_back( vector<int>({i, j-1}) );
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    string S = "abcdddeeeeaabbbcd";
    auto res = sol.largeGroupPositions( S );
    for(auto & pair: res){
        cout << pair[0] << ": " << pair[1] << endl;
    }

    return 0;
}
