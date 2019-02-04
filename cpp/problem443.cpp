#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * following the definition of compression in the problem
 * 
 * Time: Theta(n), space: Theta(1)
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        char c = chars[0];
        int n = 0, beg = 0;
        for(auto a: chars){
            if( a == c ) ++n;
            else{
                compressPiece( chars, beg, c, n );
                n = 1; c = a;
            }
        }
        compressPiece( chars, beg, c, n );
        return beg;
    }
    /**
     * compress a continuous piece
     * e.g. 
     *   x => x
     *   xxx => x3
     *   xxxxxxxxxx x=>10
     */
    void compressPiece(vector<char> &chars, int &beg, char c, int n){
        chars[ beg++ ] = c;
        
        if( n == 1 ) return;
        
        int end = beg;
        do{
            chars[ end++ ] = '0' + (n % 10);
        }while( n /= 10 );
        reverse( &chars[ beg ], &chars[end] );
        beg = end;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << sol.compress( chars ) << endl;
    MYFILE::print_range(chars) << endl;

    chars = {'a'};
    cout << sol.compress( chars ) << endl;
    MYFILE::print_range(chars) << endl;

    chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << sol.compress( chars ) << endl;
    MYFILE::print_range(chars) << endl;

    return 0;
}
