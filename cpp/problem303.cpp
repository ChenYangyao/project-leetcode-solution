#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * maximal cost in space, but fastest in time
 * 
 * The idea is to keep record of sumRange(i,j) for each pair (i,j).
 */
class NumArray {
public:
    NumArray(vector<int> nums):_n(nums.size()), _sumTable( _n*(_n+1)/2 ) {
        int indx = 0;
        for(int j=0; j<_n; ++j){
            int tempSum = 0;
            for(int i=j; i>=0; --i){
                tempSum += nums[i];
                _sumTable[ indx++ ] = tempSum;
            }
        }
    }
    int sumRange(int i, int j) {
        return _sumTable[ j*(j+1)/2 + j-i ];
    }
private:
    int _n;
    vector<int> _sumTable;
};

/**
 * minimal use of space, slowest in time
 * 
 * The idea is to directly calculate sumRange(i,j).
 */
class NumArray1 {
public:
    NumArray1(vector<int> nums): _nums(std::move(nums)) {}
    int sumRange(int i, int j) {
        return accumulate( &_nums[i], &_nums[j] + 1, 0 );
    }
private:
    vector<int> _nums;
};

/**
 * solution by using sumRange(i,j) = sumRange(0,j) - sumRange(0,i-1)
 * (assume sumRange(0,-1) = 0 ).
 * 
 * Reference: Leetcode discussion
 */ 
class NumArray2 {
public:
    NumArray2(vector<int> nums): _nums(std::move(nums)) {
        for(int i=1; i<_nums.size(); ++i) _nums[i] += _nums[i-1];
    }
    int sumRange(int i, int j) {
        return i == 0? _nums[j] : (_nums[j] - _nums[i-1]);
    }
private:
    vector<int> _nums;
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 * 
 * Below are tests from Leetcode Problem.
 */
template<typename T>
void test(){
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    T t(nums);
    cout << t.sumRange(0,2) << endl;
    cout << t.sumRange(2,5) << endl;
    cout << t.sumRange(0,5) << endl;
}
int main(int argc, char const *argv[]){   
    test<NumArray>();
    test<NumArray1>();
    test<NumArray2>();
    return 0;
}
