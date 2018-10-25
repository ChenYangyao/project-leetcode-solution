#include "mystd.h"
using namespace MYSTD;


class Solution {
public:
    int binaryGap(int N) {
        int indx = 0, max_dist = 0;
        while( N && !(N % 2) )
            N >>= 1;
        while( N ){
            ++indx;
            if( (N >>= 1)%2 ){ max_dist = std::max(indx, max_dist); indx = 0; }
        }
        return max_dist;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.binaryGap( 22 ) << endl;
    return 0;
}
