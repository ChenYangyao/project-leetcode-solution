#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * just directly find the last word
 * In the following it is s[i...j[ (reversely).
 */ 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while( i >= 0 && s[i] == ' ' ) --i;
        int j = i;
        while( j >= 0 && s[j] != ' ' ) --j;
        return i-j;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    // some extreme cases
    for(const auto &s: {"Hello World", "Hello", " ", "  Hello    World   "}){
        cout << sol.lengthOfLastWord(s) << endl;        
    }
    return 0;
}