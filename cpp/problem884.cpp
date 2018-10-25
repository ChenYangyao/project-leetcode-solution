#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> ct;
        counter(A, ct);
        counter(B, ct);
        vector<string> res;
        for( const auto & i: ct ){
            if( i.second == 1 ) res.emplace_back( i.first );
        }
        return res;
    }
    void counter(string & s, unordered_map<string, int> & ct ){
        size_t beg = 0, end;
        do{
            end = s.find(' ', beg);
            ct[ s.substr(beg, end-beg) ] += 1;
            beg = end + 1;
        }while( end < s.size() );
    }
};

int main(int argc, char const *argv[]){
    string A = "this apple is sweet", B = "this apple is sour";
    Solution sol;
    auto res = sol.uncommonFromSentences( A, B );
    for( auto & i: res ){
        cout << i << endl;
    }
    return 0;
}
