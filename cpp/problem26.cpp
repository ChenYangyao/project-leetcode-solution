#include <mystd.h>
using namespace std;
using namespace MYSTD;


/**
 * solution by filling the original list by each non-repeated element
 *
 * Time: O(n), where n = nums.size().
 * Space: constant.
 */
class Solution {
public:
    /**
     * Here index j is moving from head to tail. Once it encounters a different element,
     * it stops and nums[j] is filled into nums[i].
     */
    int removeDuplicates(vector<int>& nums) {
        if( nums.empty() )  return 0;
        int i = 1, j = 1, n = nums.size();
        int last = nums[0];
        while( j < n ){
            if( nums[j] != last ) 
                last = nums[i++] = nums[j++];
            else ++j;
        }
        nums.resize(i);
        return i;
    }
};


int main(int argc, char const *argv[]){
    Solution sol;

    // examples in Leetcode Problem
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates( nums ) << endl;
    MYFILE::print_range( nums ) << endl;

    nums.assign({1,1,2});
    cout << sol.removeDuplicates( nums ) << endl;
    MYFILE::print_range( nums ) << endl;
    return 0;
}