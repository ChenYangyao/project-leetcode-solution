#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};


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


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    cout << "\tsolution and solution2\n";
    for (int i = 1; i <= 20; ++i){
        cout << i << '\t' << sol.canWinNim(i) << '\t' << sol2.canWinNim(i) << '\n';
    }

    return 0;
}
