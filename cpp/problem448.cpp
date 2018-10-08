#include <iostream>
#include <vector>
using namespace std;

// Class: Fill the appearing position with 0
// Creat: Yangyao Chen, 2018/10/09
// References: none. This was my original idea, but proved less efficient than the Solution2 (-.-!).
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int temp;
        for(auto num: nums){
            while( num ){
                temp = nums[num-1];
                nums[num-1] = 0;
                num = temp;
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            if( nums[i] ) res.push_back( i+1 );
        }
        return res;
    }
};

// Class: Fill the appearing position with -1*original_value
// Creat: Yangyao Chen, 2018/10/09
// References: Leetcode user solution, c++ implementation.
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n;
        for(auto num: nums){
            n = abs(num) - 1;
            if( nums[n] > 0 ) nums[ n ] = -nums[ n ];
        }
        vector<int> res; n = nums.size();
        for (int i = 0; i < n; ++i){
            if( nums[i] > 0 ) res.push_back( i+1 );
        }
        return res;
    }
};
