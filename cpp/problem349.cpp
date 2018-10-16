class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1( nums1.cbegin(), nums1.cend() ), st2;
        for(auto i: nums2){
            if( st1.find(i) != st1.cend() ) st2.insert( i );
        }
        return vector<int>( st2.cbegin(), st2.cend() );
    }
};
