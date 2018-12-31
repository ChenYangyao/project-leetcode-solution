#include <mystd.h>
using namespace std;
using namespace MYSTD;

/**
 * Two-heap algorithm
 *
 * The first heap - _firstKs, is a min-heap, and always records the largest k - 1 elements.
 * The second heap - _nums, is a max-heap, always recoreds remaining elements.
 *
 * Once a new element 'val' is added, it is added to the second heap, if val < _firstKs.min().
 * Else, it is added to the first heap, and pushes aside the mininal in the first heap, into the second heap.
 * After that, the first heap remains its size to be k - 1, and the maximal of the second heap is returned. 
 */
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
    	make_heap(nums.begin(), nums.end());
    	vector<int> firstKs(k-1);
    	for (int i = 0; i < k-1; ++i){
    		firstKs[ k-2-i ] = nums.front();
    		pop_heap(nums.begin(), nums.end());
    		nums.pop_back();
    	}
    	_firstKs = std::move( firstKs );	// first heap, size k - 1, a min-heap
    	_nums = std::move( nums );			// second heap, a max-heap
    }
    int add(int val) {
  		if( _firstKs.empty() || val <= _firstKs.front() ){
  			_nums.push_back(val);
  		}else{
  			_nums.push_back( _firstKs.front() );
  			replace_top( _firstKs.begin(), _firstKs.end(), val, greater<int>() );
  		}
  		push_heap(_nums.begin(), _nums.end());
  		return _nums.front();
    }
protected:
    typedef vector<int>::iterator It;
    vector<int> _nums, _firstKs;
    int _k;

    // Using val, to push aside the top element of the heap ranged by [bit, eit).
    template<typename T>
    void replace_top( It bit, It eit, int val, T comp ){
    	// replace the top element by val
    	*bit = val;

    	// Sift down the new top element, by heap algorithm
    	long cur = 0, left = 2*cur + 1, right = 2*cur + 2;
    	int temp = bit[cur];
    	while( left < eit - bit ){
    		long next;
    		if( right < eit - bit ) next = comp(bit[left], bit[right]) ? right : left;
    		else next = left;
    		if( comp(temp, bit[next]) ){
    			bit[cur] = bit[next]; cur = next;
    		}else break;
    		left = 2*cur + 1;
    		right = 2*cur + 2;
    	}
    	bit[cur] = temp;
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
int main(int argc, char const *argv[]){
	// example in Leetcode problem
	vector<int> nums = {4,5,8,2};
	{
		KthLargest sol( 3, nums );
		for(auto i: {3,5,10,9,4}){
			cout << sol.add( i ) << endl;
		}
	}
	// example in Leetcode submiting test
	nums.clear();
	{
		KthLargest sol( 1, nums );
		for(auto i: {-3,-2,-4,0,4}){
			cout << sol.add( i ) << endl;
		}
	}

	return 0;
}