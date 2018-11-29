#include "mystd.h"
using namespace std;

/**
 * solution by step forward each sub-string that has identical characters
 */
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        char c1, c2;
        int n1, n2, i1 = 0, i2 = 0;
        while( true ){
            n1 = next(name, i1, c1);
            n2 = next(typed, i2, c2);
            if( n1 && n2 ){
                if( c1 != c2 || n1 > n2 ) return false;
            }else break;
        }
        return n1 != n2 ? false : true;;
    }
    /**
     * find the next sub-string with repeated characters, e.g. ...aaa...
     * @s:  full string
     * @beg: subs-string beginning. Then it is moved to the end of sub-string.
     * @c: repeated character in the substring
     * Length of subtring is returned.
     */
    int next(string &s, int &beg, char &c){
        if( beg == s.size() ) return 0;
        int end = beg;
        c = s[end++];
        while( end != s.size() && c == s[end] ) ++end;
        swap(beg, end);
        return beg - end;
    }
};

/**
 * a solution extracted from Leetcode User Solutions
 * This is WRONG (see below main() function) ! But it is lucky enough to pass the official test.
 */
class Solution2 {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(j < typed.size())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i == name.size())
            return true;
        else
            return false;
    }
};


int main(int argc, char const *argv[]){
    // test cases in Leetcode problem
    Solution sol;
    cout << sol.isLongPressedName( "alex", "aaleex") << endl;
    cout << sol.isLongPressedName( "saeed", "ssaaedd") << endl;
    cout << sol.isLongPressedName( "leelee", "lleeelee") << endl;
    cout << sol.isLongPressedName( "laiden", "laiden") << endl;

    // This shoud report false.
    // But this wrong answer gives true.
    Solution2 sol2;
    cout << sol2.isLongPressedName("aleexa","alexaexa") << endl;

    return 0;
}
