#include <iostream>
#include <limits>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> groups;
        for( auto & a: A ){
            insert_sort( a, 0 );
            insert_sort( a, 1 );
            groups.emplace( a );
        }
        return groups.size();
    }
    void insert_sort(string &s, int beg){
        int size = s.size();
        for( int i = beg + 2; i < size; i += 2 ){
            auto temp = s[i];
            int j = i-2;
            for(; j >= 0; j -= 2 ){
                if( s[j] > temp ){ s[j+2] = s[j]; }
                else break;
            }
            s[j+2] = temp;
        }
    }
};


int main(int argc, char const *argv[]){
    vector<string> s( {"abc","acb","bac","bca","cab","cba"} );
    Solution sol;
    cout << sol.numSpecialEquivGroups( s ) << endl;
    return 0;
}
