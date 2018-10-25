#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int> > res;
        for( const auto & i: A ){
            res.emplace_back( i.crbegin(), i.crend() );
            for( auto & j: res.back() ){ j ^= 1; }
        }
        return res;
    }
};


int main(int argc, char const *argv[]){
    vector< vector<int> > A = {{1,0,1},{1,1,0}};
    for( auto & i: A ){ for( auto & j: i ){ cout << j; } cout << endl; }

    Solution sol;
    auto res = sol.flipAndInvertImage( A );
    for( auto & i: res ){ for( auto & j: i ){ cout << j; } cout << endl; }

    return 0;
}
