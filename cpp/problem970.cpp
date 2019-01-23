#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * solution by increasingly trying each possible i and j
 */
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // When 'bound' is small, ordered set should be better.
        // We ignore this possible optimization for clarity.
        unordered_set<int> res;
        
        int xi = 1, added;
        while( xi < bound ){
            int yj = 1;
            while( (added = xi+yj) <= bound ){
                res.emplace( added );
                if( y == 1 ) break;
                yj *= y;
            }
            if( x == 1 ) break;
            xi *= x;
        }
        return vector<int>( res.begin(), res.end() );
    }
};



int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem
    auto v = sol.powerfulIntegers( 2, 3, 10 );
    MYFILE::print_range( v ) << endl;

    v = sol.powerfulIntegers( 3, 5, 15 );
    MYFILE::print_range( v ) << endl;

    return 0;
}