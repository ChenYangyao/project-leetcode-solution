
// Class: Ordinary solution by using a hash-table (map) to count the appearances of elements.
// Creat: Yangyao Chen, 2018/10/26
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: num) mp[i] ++;
        int res, appear = 0;
        for(auto pr: mp){
            if( pr.second > appear ){
                appear = pr.second; res = pr.first;
            }
        }
        return res;
    }
};


// Class: Solution by cancelling pair of different elements The majority is remained finally.
// Creat: Yangyao Chen, 2018/10/26
// References: Ziyang's solution. See swift solution set for the detail.
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), key = 0, times = 0;
        while( n --> times ){
            if( times ){
                times += (key == nums[n])?1:-1;
            }else{
                key = nums[n]; times = 1;
            }
        }
        return key;
    }
};


