#include <vector>
using namespace std;

/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (size_t i = 0; i < A.size() - 1; ++i){
            if( A[i] > A[i+1] ) return i;
        }
    }
};
*/

/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        size_t lo = 0, hi = A.size() - 2;
        size_t mid;
        while( lo != hi ){
            mid = (lo+hi)/2;
            if( A[mid] < A[mid+1] ) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int *lo = A.data(), *hi = lo + A.size() - 2, *mid = nullptr;
        while( lo != hi ){
            mid = lo + (hi - lo)/2;
            if( *mid < *(mid+1) ) lo = mid + 1;
            else hi = mid;
        }
        return lo - A.data();
    }
};


