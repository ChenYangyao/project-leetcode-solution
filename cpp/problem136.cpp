// Class: Solution to leetcode problem136
// Description:
//  - none
// Creat: Yangyao, 2018/10/02
// Modify: Yangyao TBD
//  - description none
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> nums_set;
        for( int num: nums ){
            if( nums_set.find( num ) == nums_set.end() ){
                nums_set.insert( num );
            }else{
                nums_set.erase( num );
            }
        }
        return *nums_set.begin();
    }
};
