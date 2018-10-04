#include <iostream>
#include <unordered_set>
using namespace std;

// Class: Solution by hash-determined primer number and loop-calculated set-bit number.
// Description:
//  - time complexity O(R-L).
//  - space complexity Theta(1).
// Creat: Yangyao, date 20181003
// References: none.
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0, count_setbit, temp;
        for (int i = L; i <= R; ++i){
            count_setbit = 0; temp = i;
            do{
                if( temp & 1 ) ++count_setbit;
            }while( temp >>= 1 );
            if( primes_int32.find( count_setbit ) != primes_int32.end() ) ++count;
        }
        return count;
    }
private:
    const unordered_set<int> primes_int32 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
};

// Func: Driver function to test solutions
int main(int argc, char const *argv[]){
    Solution sol;
    cout << sol.countPrimeSetBits(1,100) << endl;
    return 0;
}
