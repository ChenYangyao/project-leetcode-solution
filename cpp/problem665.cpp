#include <mystd.h>
using namespace MYSTD;
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool has_chance = true;
        int p = 0, n = nums.size();
        while( p + 1 < n ){
            if( nums[p] > nums[p+1] ){
                if( !has_chance ) return false;
                if( p == 0 || nums[p-1] <= nums[p+1] ) nums[p] = nums[p+1];
                else nums[p+1] = nums[p];
                has_chance = false;
            }
            ++p;
        }
        return true;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem
    vector<int> nums = { 4,2,3 };
    cout << sol.checkPossibility(nums) << endl;

    nums = {4,2,1};
    cout << sol.checkPossibility(nums) << endl;

    return 0;
}