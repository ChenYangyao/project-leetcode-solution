#include "mystd.h"
using namespace MYSTD;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> _mapPlate, _mapWord;
        for(auto i: licensePlate)
            if( isalpha(i) ) ++_mapPlate[tolower(i)];

        size_t len = 100;
        string *minLenWord = nullptr;
        for( auto & word: words ){
            if( word.size() >= len ) continue;
            _mapWord.clear();
            for( auto c: word ){ if( _mapPlate.find(c) != _mapPlate.end() ) ++_mapWord[c];}
            if( isComplete(_mapPlate, _mapWord) ){
                len = word.size();
                minLenWord = &word;
            }
        }

        return *minLenWord;
    }
    bool isComplete(unordered_map<char, int> & _mapPlate, unordered_map<char, int> & _mapWord){
        if( _mapPlate.size() != _mapWord.size() ) return false;
        for(const auto & i: _mapWord){
            if( i.second < _mapPlate[i.first] ) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]){
    string plate = "1s3 PSt";
    vector<string> words = {"step","steps","stripe","stepple"};
    Solution sol;
    cout << sol.shortestCompletingWord(plate, words) << endl;
    return 0;
}
