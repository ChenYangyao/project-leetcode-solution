#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


static const vector<string>
morse_code({".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---",
    "-.-",".-..","--","-.","---",
    ".--.","--.-",".-.","...","-","..-",
    "...-",".--","-..-","-.--","--.."});


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> set_words;
        for( const auto & word: words ){
            set_words.emplace( toMorse(word) );
        }
        return set_words.size();
    }
    string toMorse( const string &word ){
        string s;
        for( const auto & i : word ){
            s += morse_code[ int(i) - int('a') ];
        }
        return s;
    }
};

int main(int argc, char const *argv[]){
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution sol;
    cout << sol.uniqueMorseRepresentations( words ) << endl;
    return 0;
}
