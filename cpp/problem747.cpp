#include <mystd.h>
using namespace std;

/**
 * just find the largest and next-largest number
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
  		int max1 = nums[0], max2 = -1, indx = 0;
  		for (int i = 1, n = nums.size(); i < n; ++i){
  			if( nums[i] > max1 ){
  				max2 = max1;
  				max1 = nums[i];
  				indx = i;
  			}else if( nums[i] > max2 ){
  				max2 = nums[i];
  			}
  		}
  		return (max1 >= max2 + max2) ? indx : -1;
    }
};


int main(int argc, char const *argv[]){
	Solution sol;

	// test case in Leetcode Problem
	vector<int> nums = {3,6,1,0};
	cout << sol.dominantIndex( nums ) << endl;

	nums.assign({1,2,3,4});
	cout << sol.dominantIndex( nums ) << endl;


	return 0;
}

