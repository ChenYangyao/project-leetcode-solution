

// Class: Solution by direct comparison.
// Description:
//  - Note that this solution is good for most cases. But it cannot avoid the worst case.
//      e.g. When A = 'aaaaaaaaaaaab', B = 'baaaaaaaaaaaa', the solution takes n^2 time.
//      But this is acceptable, since the const. coefficient behind n^2 is very small when the str is not so long.
//  - It takes no extra memory.
// Creat: Yangyao Chen, 2018/10/22
class Solution {
public:
    bool rotateString(string A, string B) {
        if( A.size() != B.size() ) return false;
        if( !A.size() ) return true;
        int beg = 0;
        while( (beg = locateChar(B, A[0], beg)) != B.size() ){
            if( isIdentical( A, B, beg ) ) return true;
            ++beg;
        }
        return false;
    }
    int locateChar(const string & s, char c, int beg){
        for (int i = beg, n = s.size(); i < n; ++i){
            if( c == s[i] ) return i;
        }
        return s.size();
    }
    bool isIdentical(const string &s1, const string &s2, int beg2){
        for (int i = 0, n = s1.size(); i < n; ++i){
            if( s1[ i ] != s2[ (beg2+i)%n ] ) return false;
        }
        return true;
    }
};

// Class: Solution by find algorithm.
// Description:
//  - The 'find' method typically used KMP, so it takes 2n + n ~= 3*n time.
//  - The solution has a temporary storage of A+A, 2*n,
//      and also the `find` algorithm takes n storage if implemented with KMP.
//      So the total space cost is ~= 3*n.
//  - The time complexity is better than the first solution, while the space cost is much larger.
// Creat: Yangyao Chen, 2018/10/22
// Referencce: copied from Leetcode user-solution.
class Solution2{
public:
    bool rotateString(string A, string B) {
        return (A + A).find(B);
    }
};
