#include <string>
#include <iostream>
using namespace std;

// Class: Ordinary Solution.
// Description:
//  - this is too easy.
//  - constant space and time costs.
// Creat: Yangyao, date 20181004
// References: none.
class Solution {
public:
    int findLUSlength(string a, string b) {
        if( a.size() != b.size() ){
            return max( a.size(), b.size() );
        }else if( a == b ){
            return -1;
        }else{
            return a.size();
        }
    }
};


// Func: Driver function to test solutions
int main(int argc, char const *argv[]){

    Solution sol;

    // Test tree cases that cover all situations.
    cout << sol.findLUSlength("abc","cba") << ", expect 3" << endl;
    cout << sol.findLUSlength("abc","abc") << ", expect -1" << endl;
    cout << sol.findLUSlength("abc","abcd") << ", expect 4" << endl;

    return 0;
}
