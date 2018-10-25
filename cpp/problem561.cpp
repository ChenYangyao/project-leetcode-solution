#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        int cum = 0;
        for( size_t i = 0; i < nums.size(); i += 2 ){
            cum += nums[i];
        }
        return cum;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = {1,2,3,4};
    cout << sol.arrayPairSum( v ) << endl;
    return 0;
}
