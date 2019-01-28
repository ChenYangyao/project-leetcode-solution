#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * following the definition of binary addition
 */
class Solution {
public:
    string addBinary(string a, string b) {
        return a.size() > b.size()?_addBinary(b,a):_addBinary(a,b);
    }
    string _addBinary(string &a, string &b){
        string res;
        int sum, inc = 0, i = a.size(), j = b.size();
        while( i > 0 ){
            sum = toInt(a[--i]) + toInt(b[--j]) + inc;
            inc = (sum >= 2);
            res.push_back( toChar( inc?(sum-2):sum ) );
        }
        while( j > 0 ){
            sum = toInt(b[--j]) + inc;
            inc = (sum == 2);
            res.push_back( toChar(inc?0:sum) );
        }
        if( inc ) res.push_back('1');
        reverse(res.begin(), res.end());

        return res;
    }
    int toInt(char c){ return c - '0'; }
    char toChar(int c){ return c + '0'; }
};


int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem
    string a = "11", b = "1";
    cout << sol.addBinary(a,b) << endl;

    a = "1010"; b = "1011";
    cout << sol.addBinary(a,b) << endl;

    // other extreme cases
    a = "0"; b = "0";
    cout << sol.addBinary(a,b) << endl;

    a = "1"; b = "0";
    cout << sol.addBinary(a,b) << endl;

    return 0;
}