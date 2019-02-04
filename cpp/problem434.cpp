#include <mystd.h>
using namespace MYSTD;
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int b = -1, cnt = 0;
        while( nextNonspace(s, b) < s.size() ){
            ++cnt;
            nextSpace(s, b);
        }
        return cnt;
    }
    int nextNonspace(string &s, int &b){
        while( ++b < s.size() && s[b] == ' ' ); return b;
    }
    void nextSpace(string &s, int &b){
        while( ++b < s.size() && s[b] != ' ' );
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.countSegments( "Hello, my name is John" ) << endl;
    return 0;
}
