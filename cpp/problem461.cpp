#include <iostream>
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        return getNum1( x^y );
    }
    int getNum1( int x ){
        int ct = 0;
        do{
            ct += x % 2;
        }while( x >>= 1 );
        return ct;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.hammingDistance( 1,4 ) << endl;
    return 0;
}
