#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * ordinary merge operation
 * 
 * Here the space of nums1 should be stolen to record the result.
 * So we move the first m elements in nums1 to the back of this array,
 * to avoid that they are overwrite during merger.
 */ 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        moveBack(nums1, m, n);
        int i = n, j = 0, mpn = m + n, k = 0;
        while( i < mpn && j < n ){
            if( nums1[i] < nums2[j] ) nums1[k++] = nums1[i++];
            else nums1[k++] = nums2[j++];
        }
        if( i == mpn ) while( j < n ) nums1[k++] = nums2[j++];
    }
    void moveBack(vector<int> &nums1, int m, int n ){
        for(int i=m-1; i>=0; --i) nums1[i+n] = nums1[i];
    }
};



int main(int argc, char const *argv[]){
    Solution sol;

    // test case in Leetcode Problem
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    sol.merge(nums1, 3, nums2, 3);
    MYFILE::print_range(nums1) << endl;

    // case in Leetcode Judgement System.
    nums1.assign({1,2,4,5,6,0});
    nums2.assign({3});
    sol.merge(nums1, 5, nums2, 1);
    MYFILE::print_range(nums1) << endl;

    return 0;
}
