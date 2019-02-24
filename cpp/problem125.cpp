#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * follow the requirement of the Problem, compare only alphanumeric character
 * to check the Palindrome
 */ 
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while( true ){
            while( i < j && !isalnum(s[i]) ) ++i;
            while( i < j && !isalnum(s[j]) ) --j;
            if( i >= j ) break;
            if( isalpha(s[i]) ){
                if( !(isalpha(s[j]) && tolower(s[i]) == tolower(s[j])) ) return false;
            }else if( s[i] != s[j]){
                return false;
            }
            ++i; --j;
        }
        return true;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;
    return 0;
}