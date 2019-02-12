#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * During the one-run loop of nums, use a hash-map 
 * to record whether a number has appeared. The last
 * appearing index for a number is also recorded, and
 * is used to test whether next appearance is close
 * enough to the last appearance.
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        for(int i=0, n=nums.size(); i<n; ++i){
            auto it = m.find( nums[i] );
            if( it != m.end() ){
                if( i - it->second <= k  ) return true;
                else it->second = i;
            }else{
                m.emplace(nums[i], i);
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    
    // test cases in Leetcode Problem
    vector<int> nums = {1,2,3,1};
    cout << sol.containsNearbyDuplicate(nums, 3) << endl;

    nums.assign({1,0,1,1});
    cout << sol.containsNearbyDuplicate(nums, 1) << endl;

    nums.assign({1,2,3,1,2,3});
    cout << sol.containsNearbyDuplicate(nums, 2) << endl;

    return 0;
}
