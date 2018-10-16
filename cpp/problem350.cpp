class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        vector<int> res;
        for(auto i: nums1) mp1[i] ++;
        for(auto i: nums2) mp2[i] ++;
        for(const auto &pr: nums2){
            auto temp = mp1.find(pr.first);
            if( temp != mp1.cend() )
                fill_n( back_inserter(res), min( pr.second, temp->second ), pr.first );
        }
        return res;
    }
};
