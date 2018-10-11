#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>
using namespace std;

// Class: Ordinary solution, with BFS-like treatment of input string.
// Description:
//  - Extend the 'leaves' nodes by the BFS-like traversal.
// Creat: Yangyao Chen, 2018/10/12
// References: none
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {""};
        for( auto c: S ){
            if( isdigit( c ) ){
                for( auto & i: res ) i += c;
            }else{
                char c_lower = tolower(c), c_upper = toupper(c);
                for (int i = 0, size = res.size(); i < size; ++i){
                    res.emplace_back( res[i] + c_upper );
                    res[i] += c_lower;
                }
            }
        }
        return res;
    }
};

// Class: Solution by allocating memory in advanve.
// Description:
//  - count the number of alphabetic bytes in the input string S, this will directly give the length of output vector.
//  - allocate the memory for the result before doing computation.
// Creat: Yangyao Chen, 2018/10/20
// References:
//      Thanks Ziyang for the discussion. This solution may only have performance lifting for the C-language.
//      This is not suitable in Python, Swift..., where the string type is not mutable.
class Solution2 {
public:
    vector<string> letterCasePermutation(string S) {
        for(auto & c: S) c = toupper(c);
        int n_alpha = count_if( S.cbegin(), S.cend(), [](int c)->bool{ return isalpha(c); } );
        vector<string> res( pow(2, n_alpha), S );

        for (int i = S.size() - 1, step = 1, n = res.size(); i >= 0; --i){
            if( isdigit(S[i]) ) continue;
            char c_lower = tolower(S[i]);
            for (int j = 0; j < n; j += step*2)
                for (int k = j; k < step+j; ++k)
                    res[k][i] = c_lower;
            step *= 2;
        }
        return res;
    }
    static int pow(int x, int n){ int res = 1; for (int i = 0; i < n; ++i) res *= x; return res;}
};


// Func: For measuring the run time
template<typename T>
double sec( T f, int repeat, string & s ){
    clock_t t1 = clock();
    for (int i = 0; i < repeat; ++i){
        f.letterCasePermutation(s);
    }
    clock_t t2 = clock();
    return double(t2-t1)/CLOCKS_PER_SEC;
}


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // An example of solution
    string s(4,'a'); s += "123";
    for(const auto & i: sol.letterCasePermutation(s)){
        cout << i << '\t';
    }
    cout << endl;

    // Test time with different lengths of string
    printf("len of str\trepeat\tt1\tt2\n");
    for (int i = 0; i < 15; ++i){
        string s(i+2,'a'); int repeat = 10000000/Solution2::pow(2,i+2);
        auto t1 = sec(sol, repeat, s);
        auto t2 = sec(sol2, repeat, s);
        printf("%d\t\t%d\t%.3f\t%.3f\n", i+2, repeat, t1, t2);
    }

    // Test time with fix length of string, but with different fraction of digital bytes
    printf("fraction of number\tt1\tt2\n");
    for (int i = 0; i < 15; ++i){
        string s = string(i+2,'a') + string(16-i, '1'); int repeat = 10000000/Solution2::pow(2,i+2);
        auto t1 = sec(sol, repeat, s);
        auto t2 = sec(sol2, repeat, s);
        printf("%.3f\t\t\t%.3f\t%.3f\n", double(16-i)/18, t1, t2);
    }

    return 0;
}
