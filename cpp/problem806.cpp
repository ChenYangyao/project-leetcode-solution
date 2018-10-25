#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1, units = 0;
        for( const auto & i : S ){
            units += widths[ i - 'a' ];
            if( units > 100 ){
                ++ lines;
                units = widths[ i - 'a' ];
            }
        }
        return vector<int>({lines, units});
    }
};
