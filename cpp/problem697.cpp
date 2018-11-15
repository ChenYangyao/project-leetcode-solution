#include "mystd.h"
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map< int, tuple<int,int,int> > counter;
        for (int i = 0, n = nums.size(); i < n; ++i){
            auto it = counter.find( nums[i] );
            if( it == counter.end() ){
                counter.emplace( nums[i], tuple<int,int,int>(1, i, i) );
            }else{
                ++get<0>(it->second);
                get<2>(it->second) = i;
            }
        }

        int minsublength = INT_MAX, maxcount = 0, sublength, count;
        for(const auto & i: counter){
            count = get<0>(i.second);
            sublength = get<2>(i.second) - get<1>(i.second);
            if( count > maxcount ){
                maxcount = count;
                minsublength = sublength;
            }else if( count == maxcount && sublength < minsublength ){
                minsublength = sublength;
            }
        }
        return minsublength + 1;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v1 = {1,2,3,4,2,6,7,8,9,9},
        v2 = {1,2,3,4,5,6,2,4,9,10};

    Solution sol;
    cout << sol.findShortestSubArray( v1 ) << endl;
    cout << sol.findShortestSubArray( v2 ) << endl;
    return 0;
}
