#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * 1-d nearest searching
 * For this case, the easiest way is to sort two arrays.
 * But it is also possible to only sort the heaters, and 
 * find the nearest point in heaters to each point in houses.
 * 
 * Author: Yangyao, 2019/02/18
 */ 
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MAX); heaters.push_back(INT_MIN);
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        long radius = 0; int i = 1;
        for(auto house: houses){
            while( house > heaters[i] ) ++i;
            radius = max( radius, 
                min( heaters[i]-long(house), long(house)-heaters[i-1] ) 
            );
        }
        return radius;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // test cases in Leetcode Problem
    vector<int> houses = {1,2,3}, heaters = {2};
    cout << sol.findRadius(houses, heaters) << endl;

    houses.assign({1,2,3,4}); heaters.assign({1,4});
    cout << sol.findRadius(houses, heaters) << endl;

    // a variant of the above
    houses.assign({1,2,3,6}); heaters.assign({1,4});
    cout << sol.findRadius(houses, heaters) << endl;
    return 0;
}