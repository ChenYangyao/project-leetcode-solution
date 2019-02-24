#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * find pairs directly by hash-set.
 * Time and space: linear with nums.length
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        if( k > 0 ){
            std::unordered_set<int> st( nums.begin(), nums.end() );
            for(const auto &i: st){
                if( st.find( i+k ) != st.end() ) ++cnt;
            }
        }else if( k == 0 ){
            std::unordered_map<int, char> st;
            for(auto i: nums){
                auto ret = st.emplace( i, 1 );
                if( !ret.second && ret.first->second ){ 
                    ++cnt; ret.first->second = 0; 
                }
            }
        }
        return cnt;
    }
};

/**
 * find pairs (i,j) by searching for after i in sorted array
 * Space: constant, Time: O(n*logn) where n = nums.length
 */
class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        if( k < 0 ) return 0;
        int cnt = 0;
        sort( nums.begin(), nums.end() );
        for(int i=0, j=0, n=nums.size(), temp=INT_MIN; i<n; ++i){
            if( nums[i] != temp ){
                int dest = nums[i]+k;
                if( !k ) j=i+1;
                while( j < n && nums[j] < dest ) ++j;
                if( j < n && nums[j] == dest ) ++cnt;
                temp = nums[i];
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;

    // examples in Leetcode Problem
    vector<int> nums = {3,1,4,1,5};
    cout << sol.findPairs( nums, 2 ) << ", " << sol2.findPairs( nums, 2 ) << endl;

    nums = {1,2,3,4,5};
    cout << sol.findPairs( nums, 1 ) << ", " << sol2.findPairs( nums, 1 ) << endl;

    nums = {1,3,1,5,4};
    cout << sol.findPairs( nums, 0 ) << ", " << sol2.findPairs( nums, 0 ) << endl;

    return 0;
}