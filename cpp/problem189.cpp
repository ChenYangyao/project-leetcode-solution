#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * directly move k-step by moving k individual 1 steps
 * e.g. nums = [1,2,3,4,5,6,7], k = 3, let n = nums.length
 * Steps are:
 * move 1 step: nums = [2,3,4,5,6,7,1]
 * move 1 step: nums = [3,4,5,6,7,1,2]
 * move 1 step: nums = [4,5,6,7,1,2,3]
 * This is a bad solution, with time O(k*n), despite of constant space.
 */ 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if( nums.size() <= 1 || (k %= nums.size()) == 0 ) return;
        for(int i=0; i<k; ++i){
            rotateOne(nums);
        }
    }
    void rotateOne(vector<int> &nums){
        for(int i=nums.size()-1; i > 0; --i)
            swap( nums[i], nums[i-1] );
    }
};

/**
 * a well-known solution with three 'reverse'
 * e.g. nums = [1,2,3,4,5,6,7], k = 3, let n = nums.length
 * Steps are:
 * 1. reverse nums[1...n[, then nums = [7,6,5,4,3,2,1]
 * 2. reverse nums[1...k[, then nums = [5,6,7,4,3,2,1]
 * 3. reverse nums[k...n[, then nums = [5,6,7,1,2,3,4]
 * Time: O(n), constant space.
 * This is easy to write, but is not the best in time. 
 * In fact it takes n swaps (3*n value-assignments).
 */ 
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        if( nums.size() <= 1 || (k %= nums.size()) == 0 ) return;
        reverse( nums.begin(), nums.end() );
        reverse( nums.begin(), nums.begin() + k );
        reverse( nums.begin() + k, nums.end() );
    }
};

/**
 * a more complicated solution
 * e.g. nums = [1,2,3,4,5,6,7,8,9,10,11], k = 3, let n = nums.length
 * Steps are:
 * 1. move first k elemnts forward by k steps, nums = [4,5,6,1,2,3,7,8,9,10,11]
 * 2. move first k elments forward by 2*k steps, nums = [7,8,9,1,2,3,4,5,6,10,11]
 * 3. move the first 2 elements forward by 3*k steps, nums = [10,11,9,1,2,3,4,5,6,7,8]
 * 4. adjust the first 3 elements to correct position, nums = [9,10,11,1,2,3,4,5,6,7,8]
 *      this can be done by recursively calling the rotate function.
 * Time: O(n), constant space.
 * It takes ~n swaps (3*n value-assignments).
 */ 
class Solution3 {
public:
    void rotate(vector<int>& nums, int k){
        rotate( nums, k, nums.size() );
    }
    void rotate(vector<int>& nums, int k, int n) {
        if( nums.size() <= 1 || (k %= n ) == 0 ) return;

        int b = k;
        while( n - b >= k ){
            for(int i=0; i<k; ++i){
                swap( nums[i], nums[b+i] );
            }
            b+=k;
        }
        for(int i=0; i<n-b; ++i){
            swap(nums[i], nums[b+i]);
        }
        rotate(nums, k-(n-b), k);
    }
};

/**
 * keep copies of the last k elements
 * This is best in time, but consume extra O(k) memory.
 * Let n = nums.length
 * Time: O(n). To be exact, it is 2*k + (n-k) = n+k value-assignments
 */ 
class Solution4 {
public:
    void rotate(vector<int>& nums, int k){
        if( nums.size() <= 1 || (k %= nums.size() ) == 0 ) return;
        vector<int> temps(nums.end()-k, nums.end());
        for(int i=nums.size()-k-1; i>=0; --i){
            nums[i+k] = nums[i];
        }
        for(int i=0; i<k; ++i){
            nums[i] = temps[i];
        }
    }
};


int main(int argc, char const *argv[]){
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;
    Solution4 sol4;

    // example in Leetcode Problem
    vector<int> nums = {1,2,3,4,5,6,7}, temp;

    temp = nums;
    sol.rotate( temp, 3 );
    MYFILE::print_range( temp ) << endl;

    temp = nums;
    sol2.rotate( temp, 3 );
    MYFILE::print_range( temp ) << endl;

    temp = nums;
    sol3.rotate( temp, 3 );
    MYFILE::print_range( temp ) << endl;

    temp = nums;
    sol4.rotate( temp, 3 );
    MYFILE::print_range( temp ) << endl;
    return 0;
}