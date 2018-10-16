#include <iostream>
using namespace std;


// Class: Solution by add each bit and carry left.
// Description:
//  - add each bit by 'XOR'.
//  - if 1 + 1 encountered, 'AND' will give a 1, and <<  carries it to higher bit.
//  - loop until there is no carries bit.
// Creat: Yangyao Chen, 2018/10/12
// References: none.
// Note:
//  - Negative number is represented by complementary code. The addition including negatives is unified with that only includes positive number.
class Solution {
public:
    int getSum(int a, int b) {
        int _xor;
        while(b){
            _xor = a ^ b;
            b = (a & b) << 1;
            a = _xor;
        }
        return a;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.getSum(2013,100) << endl;
    cout << sol.getSum(2013,-3) << endl;
    cout << sol.getSum(2013,-4026) << endl;
    return 0;
}
