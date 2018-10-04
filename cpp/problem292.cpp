#include <iostream>
#include <vector>
using namespace std;

// Class: Solution with mathematica thoughts.
// Description:
//  - from mathematica, if n % 4 == 0, then i will fail!
//  - constant space and time costs.
// Creat: Yangyao, date 20181004
// References: none.
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

// Class: Solution with iteration.
// Description:
//  - use a deque-like structure to keep former result.
//  - constant space cost.
//  - linear time cost = Theta(n).
// Creat: Yangyao, date 20181004
// References: none.
class Solution2 {
public:
    bool canWinNim(int n) {
        bool history[3] = {true, true, false};
        int findex = 2;
        for (int i = 0; i < n; ++i){
            findex = (findex+1)%3;
            history[findex] = (history[0] && history[1] && history[2])?false:true;
        }
        return history[findex];
    }
};

template<typename T>
void check_time( T &sol, int repeat = 1000, int n = 100 ){
    clock_t t1 = clock();
    for (int i = 0; i < repeat; ++i){
        sol.canWinNim(n);
    }
    clock_t t2 = clock();
    cout << "time cost: " << double(t2-t1)/CLOCKS_PER_SEC << endl;
}


// Func: Driver function to test solutions
int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // Test solutions by different inputs.
    cout << "\tsolution and solution2\n";
    for (int i = 1; i <= 10; ++i){
        cout << i << '\t' << sol.canWinNim(i) << '\t' << sol2.canWinNim(i) << '\n';
    }

    // Compare efficiency of solutions.
    check_time(sol);
    check_time(sol2);

    return 0;
}
