// Library needed by solutions should be imported by hand.
// Although these are automatically imported in Leetcode.
#include <vector>
#include <iostream>
#include <unordered_set>
#include <ctime>
using namespace std;


// Class: Solution by linear search.
// Description:
//  - linearly search the stone in jewels sequential list.
//  - time complexity Theta(len(J)*len(S)).
//  - space complexity Theta(1).
// Creat: Yangyao, date 20181003
// References: none. (always put the references here, e.g. leetcode official solution, leetcode user's solution)
// Modify: Yangyao, date 20181003
//  - add some notes.
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for( auto s: S ){
            if( isJewel(J, s) ) ++count;
        }
        return count;
    }
    // Func: Determine if a stone is jewel.
    // @ - [J] sequential list of jewels.
    //   - [s] stone to be judged.
    // % - [bool] true if it is jewel, false if else.
    bool isJewel(const string &J, char s){
        for( auto j: J ){
            if( s == j ) return true;
        }
        return false;
    }
};


// Class: Solution by hash table
// Description:
//  - use unordered set to speed up searching.
//  - time complexity is reduced to Theta(len(S))
//  - extra space Theta(len(J))
// Creat: Yangyao, date 20181003
// Reference: none.
class Solution2 {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char> set_J(J.cbegin(),J.cend());
        for( auto s: S ){
            if( set_J.find(s) != set_J.cend() ) ++count;
        }
        return count;
    }
};


// Func: Driver function to test solutions
int main(int argc, char const *argv[]){
    string J = "aAbcefoOpPsSdD", S = "aAAbbbbsdfgrtyytuyiuiusdfsdfhfhfhhbsdfjsjfuaewyf";
    Solution sol;
    Solution2 sol2;

    const int repeat = 1000000;
    clock_t t1 = 0, t2 = 0; int total = 0;

    // test the time for linear searching
    t1 = clock();
    for (int i = 0; i < repeat; ++i){
        total += sol.numJewelsInStones( J, S );
    }
    t2 = clock();
    cout << "total stone " << total << endl;
    cout << "time by linear searching " << double(t2-t1)/CLOCKS_PER_SEC << endl;

    // test the time for hash searching
    total = 0;
    t1 = clock();
    for (int i = 0; i < repeat; ++i){
        total += sol2.numJewelsInStones( J, S );
    }
    t2 = clock();
    cout << "total stone " << total << endl;
    cout << "time by hash searching " << double(t2-t1)/CLOCKS_PER_SEC << endl;

    return 0;
}
