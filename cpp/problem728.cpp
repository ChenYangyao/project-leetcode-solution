#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i){
            if( isSelfDividing(i) ) res.emplace_back( i );
        }
        return res;
    }
    bool isSelfDividing(int x){
        int _x = x, bit = 0;
        while ( _x > 0 ){
            bit = _x % 10;
            _x = _x / 10;
            if( bit == 0 || x % bit ){ return false; }
        }
        return true;
    }
};
