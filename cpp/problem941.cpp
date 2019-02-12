#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * just follow the definition of valid mountain array
 */ 
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, n = A.size();
        while( i + 1 < n && A[i] < A[i+1] ) ++i;
        if( i == 0 || i == n - 1 ) return false;

        while( i + 1 < n && A[i] > A[i+1] ) ++i;
        if( i < A.size() - 1 ) return false;
        return true;        
    }
};

/**
 * add a sentinel value at the end of array
 * This small change reduces half of the total number of
 * comparisons, seen from the extreme simplification of 
 * while loop.
 * 
 * Author: Yangyao, 2019/2/12
 */ 
class Solution2 {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, n = A.size();
        if( n < 3 ) return false;

        A.push_back(A.back());
        while( A[i] < A[i+1] ) ++i;
        if( i == 0 || i == n - 1 ) return false;
        while( A[i] > A[i+1] ) ++i;
        if( i < n - 1 ) return false;
        A.pop_back();

        return true;
    }
};

template<typename T>
void test(){
    T sol;
    vector<int> A = {2,1};
    cout << sol.validMountainArray(A) << endl;
    A.assign({3,5,5});
    cout << sol.validMountainArray(A) << endl;
    A.assign({0,3,2,1});
    cout << sol.validMountainArray(A) << endl;
    
    A.assign({1});
    cout << sol.validMountainArray(A) << endl;
    A.assign({1,2});
    cout << sol.validMountainArray(A) << endl;
    A.assign({1,2,3});
    cout << sol.validMountainArray(A) << endl;
}

int main(int argc, char const *argv[]){
    test<Solution>();
    test<Solution2>();
    return 0;
}
