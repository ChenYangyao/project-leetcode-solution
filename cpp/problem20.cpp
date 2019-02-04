#include <mystd.h>
using namespace MYSTD;
using namespace std;


/**
 * solution with stack
 * 
 * This is a very typical usage of stack.
 * Author: Yangyao, 2019/02/04
 */ 
#define MATCH_BRACKET(l,r) \
    case r:\
        if( stk.empty() || stk.top() != l ) return false;\
        else stk.pop();\
        break;

class Solution {
public:
    bool isValid(string s) {   
        stack<char> stk;
        for(auto c: s) switch(c){
            case '(': case '[': case '{':
                stk.push(c);
                break;
            MATCH_BRACKET('(',')')
            MATCH_BRACKET('[',']')
            MATCH_BRACKET('{','}')
        }
        return stk.empty();
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    string s;

    // cases in Leetcode Problem
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("(]") << endl;
    cout << sol.isValid("([)]") << endl;
    cout << sol.isValid("{[]}") << endl;
    // case in Leetcode Judgement System
    cout << sol.isValid("]") << endl;

    return 0;
}
