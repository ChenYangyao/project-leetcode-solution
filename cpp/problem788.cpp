#include "iostream"
using namespace std;


class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0, rotated;
        for (int i = 1; i <= N; ++i)
            if( rotated = rotate(i) ) count += rotated != i;
        return count;
    }
    int rotate(int n){
        int rotated = 0, base = 1;
        while( n ){
            int rem = n%10;
            switch(rem){
                case 0: case 1: case 8:
                    rotated += base * rem;
                    break;
                case 2:
                    rotated += base * 5;
                    break;
                case 5:
                    rotated += base * 2;
                    break;
                case 6:
                    rotated += base * 9;
                    break;
                case 9:
                    rotated += base * 6;
                    break;
                default:
                    return 0;
            }
            base *= 10;
            n /= 10;
        }
        return rotated;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.rotatedDigits( 10 ) << endl;
    return 0;
}
