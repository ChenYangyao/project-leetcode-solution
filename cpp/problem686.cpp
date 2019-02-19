#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by extending string A gradually, and matching string B
 * at each step.
 * Time: O(A.length + B.length), Space: O(A.length + B.length).
 * If A.length << B.length, time goes even worse.
 */ 
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s = A;
        do{
            if( s.find(B) != s.npos ) 
                return s.size() / A.size();
            s += A;
        }while( s.size() < B.size() + 2*A.size() );
        return -1;
    }
};

/**
 * avoid repeated search
 * Directly form a string A+A+... long enough, and match string B.
 * Time: O(A.length + B.length), Space: O(A.length + B.length).
 */ 
class Solution2 {
public:
    int repeatedStringMatch(string A, string B) {
        string s = A;
        while( s.size() < B.size() + 2*A.size() ) s += A;

        size_t pos = s.find(B);
        if( pos != s.npos ) return ceil(pos+B.size(), A.size());
        return -1;
    }
    size_t ceil( size_t a, size_t b ){
        return (a + b - 1) / b;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    
    string A = "abcd", B = "cdabcdab";
    cout << sol.repeatedStringMatch(A, B) << endl;
    cout << sol2.repeatedStringMatch(A, B) << endl;

    return 0;
}
