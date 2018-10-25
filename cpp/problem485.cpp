#include "mystd.h"
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_consecutive = 0;
        for( auto num: nums ){
            if( num == 0 ){
                if( count ){
                    max_consecutive = max( max_consecutive, count );
                    count = 0;
                }
            }
            else{
                ++count;
            }
        }
        return max(max_consecutive, count);
    }
};


int main(int argc, char const *argv[]){
    vector<int> nums = {1,1,0,1,1,1};
    Solution sol;
    cout << sol.findMaxConsecutiveOnes( nums ) << endl;
    return 0;
}
