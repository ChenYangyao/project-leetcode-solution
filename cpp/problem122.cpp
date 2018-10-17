#include <vector>
#include <iostream>
using namespace std;


// Class: Find the increasing interval.
// Description:
//  - Sum over all intervals where the sequence is increasing.
// Creat: Yangyao Chen, 2018/10/18
// Note: You may directly sum over prices[i+1] - prices[i] when increasing.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto it = prices.begin(), b = it, e = prices.end();
        int res = 0;
        if( b == e ){ return res; }
        while( (++it) !=  e ){
            if( *it < *(it-1) ){
                res += *(it-1) - *b;
                b = it;
            }
        }
        return res + *(it-1) - *b;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    vector<int> prices = {1,2,3,4,5};
    cout << sol.maxProfit(prices) << endl;

    prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
