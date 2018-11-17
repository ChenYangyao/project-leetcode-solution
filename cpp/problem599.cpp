#include "mystd.h"
using namespace std;

/**
 * solution by using hash-table of to search matched item
 * Description:
 *  - Covert list1 to a hash-table, with item and its index being recorded.
 *  - For each item in list2 (index i), find the matched item in hash-table (index j).
 *      if the sum of indexes is smallest, record it, otherwise ignore it.
 */
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indxs;
        for (int i = 0, n = list1.size(); i < n; ++i){
            indxs.emplace( list1[i], i );
        }

        int sum_indx = INT_MAX;
        vector<string> res;
        for (int i = 0, n =list2.size(); i < n; ++i){
            auto it = indxs.find( list2[i] );
            if( it != indxs.end() ){
                if( i + it->second <= sum_indx ){
                    if( i + it->second < sum_indx ){
                        sum_indx = i + it->second;
                        res.clear();
                    }
                    res.push_back( it->first );
                }
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    // We test the solution by the data provided by the Leetcode website.
    vector<string> s1s = {"Shogun", "Tapioca Express", "Burger King", "KFC"},
        s2s = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    Solution sol;
    auto res = sol.findRestaurant( s1s, s2s );
    for(auto & s: res){
        cout << s << endl;
    }

    // Add same item to each, now the smallest sum of indexes becomes redundant.
    s1s.back() = "Shitang of THU";
    s2s.front() = "Shitang of THU";
    res = sol.findRestaurant( s1s, s2s );
    for(auto & s: res){
        cout << s << endl;
    }

    return 0;
}
