#include <mystd.h>
using namespace MYSTD;


class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> dist( S.size() );
        int end = S.find( C );

        int beg = end, count = 1;
        while( --beg >= 0 ) dist[ beg ] = count++;

        beg = end;
        while( (end = S.find(C, beg+1)) >= 0 ){
            int i = beg, j = end, count = 0;
            while( j >= i ) dist[i++] = dist[j--] = count++;
            beg = end;
        }

        count = 1;
        while( ++beg < S.size() ) dist[beg] = count++;

        return dist;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    auto res = sol.shortestToChar("aaba", 'b');
    for (size_t i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
