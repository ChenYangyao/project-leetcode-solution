#include <mystd.h>
using namespace MYSTD;
using namespace std;

// Forward declaration of isBadVersion API.
// Here, for example, it is bad when version >= 5.
bool isBadVersion(int version){
    return version >= 5;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int b = 1, e = n, c;
        while( b != e ){
            c = b + (e-b)/2;
            if( isBadVersion(c) ) e = c;
            else b = c+1;
        }
        return b;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    // a simple example which should output '5'.
    cout << sol.firstBadVersion(100) << endl;
    return 0;
}