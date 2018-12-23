#include <mystd.h>
using namespace std;

/**
 * easiest searching algorithm for sorted sequential list
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0, e = nums.size();
        while(b < e) {
            int c = b + (e-b)/2;
            if( target < nums[c] ) e = c;
            else if( nums[c] < target ) b = c+1;
            else return c;
        }
      	return -1;
    }
};



int main(int argc, char const *argv[]){
	// test example in Leetcode website
	Solution sol;
	vector<int> v = {-1,0,3,5,9,12};
	cout << sol.search( v, 9 ) << endl;
	cout << sol.search( v, 2 ) << endl;
	return 0;
}