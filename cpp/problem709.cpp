#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string s = str;
        for( auto & i : s ){ i = tolower(i); }
        return s;
    }
};


