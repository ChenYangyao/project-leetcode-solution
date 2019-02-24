#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * a well-know solution.
 * Just use all primers below n to check and exclude the non-primers.
 */ 
class Solution {
public:
    int countPrimes(int n) {
        if( n <= 2 ) return 0;
        int uplim = sqrt( n - 0.5 );
        vector<int> p(n, 1);     
        for(int i=2; i<=uplim; ++i){
            if( !p[i] ) continue;
            for(int j=2*i; j<n; j+=i ) p[j] = 0;
        }
        int cnt = 0;
        for(int i=2; i<n; ++i) if( p[i] ) ++cnt;
        return cnt;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    // marginal cases 10,11,12 and large cases 100,1000
    for(const auto &i: {10,11,12,100,1000}){
        cout << sol.countPrimes(i) << endl;
    }
    return 0;
}