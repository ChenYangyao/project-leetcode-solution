#include "mystd.h"
using namespace std;

/**
 * pay attention to the 'continuous' condition of L
 */
class Solution {
public:
    bool checkRecord(string s) {
        int ct_A = 0, ct_L = 0;
        for(auto c: s){
            ct_A += c=='A';
            ct_L = (c=='L')?(ct_L+1):0;
            if( ct_A > 1 || ct_L > 2 ) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    string s1 = "PPALLP", s2 = "PPALLL", s3 = "LALL";

    cout<< sol.checkRecord(s1) << '\t'
        << sol.checkRecord(s2) << '\t'
        << sol.checkRecord(s3) << endl;
    return 0;
}
