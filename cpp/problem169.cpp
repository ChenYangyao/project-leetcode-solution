

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
