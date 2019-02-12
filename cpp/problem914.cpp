#include <mystd.h>
using namespace MYSTD;
using namespace std;    

/**
 * direct pick up some possible X and check if one of them
 * is common divisor of all count
 */ 
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> card2cnt;
        for(auto i: deck) ++card2cnt[i];

        // find the count of least appearance
        int minCnt = INT_MAX;
        for(const auto &i: card2cnt) minCnt = min( minCnt, i.second );
        if( minCnt < 2 ) return false;

        // try all possible group size X
        // X must either be the min-count of numbers, or a divisor
        // of the min-count.
        if( isValidX(card2cnt,minCnt) ) return true;
        int maxX = sqrt(minCnt + 1.0);
        for(int i=2; i<=maxX; ++i){
            if( minCnt % i == 0 && 
                ( isValidX(card2cnt,i) || isValidX(card2cnt,minCnt/i) ) 
            ) return true;
        }
        return false;
    }
    /**
     * check if X is a divisor of all counts
     */ 
    bool isValidX(unordered_map<int, int> &card2cnt, int X){
        for(const auto &i: card2cnt){
            if( i.second % X ) return false;
        }
        return true;
    }
};

/**
 * it is easy to show that
 * (1) X could be the gcd of all counts if their gcd >= 2.
 * (2) the gcd of [x1, x2, x3, ..., xn] = the gcd of [ gcd of x1 and x2, x3, ..., xn ].
 * 
 * Reference: Leetcode User Soution
 */
class Solution2{
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if( deck.empty() ) return false;
        
        unordered_map<int, int> card2cnt;
        for(auto i: deck) ++card2cnt[i];

        int gcd = card2cnt.begin()->second;
        for(const auto &i: card2cnt){
            gcd = getGcd(gcd, i.second);
        }
        return gcd >= 2;
    }
    int getGcd( int x, int y ){
        if( x < y ) swap(x,y);
        int temp = x%y;
        while( temp ){
            x = y;
            y = temp;
            temp = x%y;
        }
        return y;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // examples in Leetcode Problem
    vector<int> deck = {1,2,3,4,4,3,2,1};
    cout << sol.hasGroupsSizeX(deck) << ' ' << sol2.hasGroupsSizeX(deck) << endl;

    deck.assign( {1,1,1,2,2,2,3,3} );
    cout << sol.hasGroupsSizeX(deck) << ' ' << sol2.hasGroupsSizeX(deck) << endl;
    
    deck.assign( {1} );
    cout << sol.hasGroupsSizeX(deck) << ' ' << sol2.hasGroupsSizeX(deck) << endl;

    deck.assign( {1,1} );
    cout << sol.hasGroupsSizeX(deck) << ' ' << sol2.hasGroupsSizeX(deck) << endl;

    deck.assign( {1,1,2,2,2,2} );
    cout << sol.hasGroupsSizeX(deck) << ' ' << sol2.hasGroupsSizeX(deck) << endl;
    return 0;
}
