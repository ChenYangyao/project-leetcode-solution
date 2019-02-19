#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * solution by first determining how many empty plots are
 * there between each two filled plots, and then calculate
 * how many plants can be inserted between two filled plots.
 * 
 * Author: Yangyao, 2019/02/19
 */ 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = -1; 
        nextOne(flowerbed, i);
        if( i == flowerbed.size() ) return (i + 1)>>1 >= n;

        int nget = i/2, j = i;
        while( nget < n && nextOne(flowerbed, j) != flowerbed.size() ){
            nget += (j - i - 2)>>1;
            i = j;
        }
        if( nget >= n ) return true;
        nget += (j-i-1)>>1;
        return nget >= n;
    }
    int nextOne(vector<int> &v, int &i){
        while( ++i < v.size() && !v[i] ) ;
        return i;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem  
    vector<int> flowerbed = {1,0,0,0,1};
    cout << sol.canPlaceFlowers(flowerbed, 1) << "\n\n";
    cout << sol.canPlaceFlowers(flowerbed, 2) << "\n\n";
    // add some test cases
    flowerbed.push_back(0);
    cout << sol.canPlaceFlowers(flowerbed, 2) << "\n\n";
    flowerbed.push_back(0);
    cout << sol.canPlaceFlowers(flowerbed, 2) << "\n\n";
    return 0;
}