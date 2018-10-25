#include <iostream>
#include <cctype>
using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        if( islower(word[0]) ){
            for(auto c: word) if( isupper(c) ) return false;
            return true;
        }else{
            if( word.size() == 1 ) return true;
            if( isupper(word[1]) ){
                for(auto c: word) if( islower(c) ){ return false; }
                return true;
            }
            for (int i = 2, n = word.size(); i < n; ++i){
                if( isupper(word[i]) ) return false;
            }
            return true;
        }
        return true;
    }
};


int main(int argc, char const *argv[]){
    string s = "ffffffffffffffffF";
    Solution sol;
    cout << sol.detectCapitalUse(s) << endl;
    return 0;
}
