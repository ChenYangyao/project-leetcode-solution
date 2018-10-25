#include "vector"
#include "iostream"
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 || matrix[0].size() == 0 ) return false;
        if( target < matrix[0][0] || target > matrix.back().back() ) return false;
        int beg = 0, end = matrix.size(), mid;
        while(end - beg > 1){
            mid = beg + (end - beg)/2;
            int val = matrix[mid][0];
            if( target < val) end = mid;
            else if( val < target ) beg = mid;
            else return true;
        }
        int row = beg;
        beg = 0; end = matrix[row].size();
        while( end - beg ){
            mid = beg + (end - beg)/2;
            int val = matrix[row][mid];
            if( target < val ) end = mid;
            else if( val < target ) beg = mid+1;
            else return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > v = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    Solution sol;
    cout << sol.searchMatrix( v, 3 ) << endl;
    return 0;
}
