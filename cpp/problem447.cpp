#include "mystd.h"
#include "myfile_csv.h"
using namespace MYSTD;
using namespace std;


/**
 * a O(n^3) solution
 * Author: Yangyao, 2018/11/08
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = 0;
        for (int i = 0, npts = points.size(); i < npts; ++i)
        for (int j = i+1; j < npts; ++j)
        for (int k = j+1; k < npts; ++k){
            n += n_eq(points[i],points[j],points[k]);
        }
        return n;
    }
    int n_eq(pair<int,int> &p1, pair<int,int> &p2, pair<int,int> &p3){
        int n = 0;
        int s_d1 = s_dist(p1,p2), s_d2 = s_dist(p1,p3), s_d3 = s_dist(p2,p3);
        if( s_d1 == s_d2 ){
            if( s_d1 == s_d3 ) n=6;
            else n=2;
        }else if(s_d1 == s_d3){
            n=2;
        }else if(s_d2 == s_d3){
            n=2;
        }
        return n;
    }
    int s_dist(pair<int,int> &p1, pair<int,int> &p2){
        int dx = p1.first - p2.first, dy = p1.second - p2.second;
        return dx*dx + dy*dy;
    }
};

/**
 * a O(n^2) solution
 * Author: Yangyao, 2018/11/08
 * Reference; Leetcode user solution.
 */
class Solution2 {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int npts = points.size();
        unordered_map<int, int> ct;
        int res = 0;
        for(int i=0; i<npts; ++i){
            for (int j = 0; j < npts; ++j){
                ++ct[ s_dist( points[i], points[j] ) ];
            }
            for(const auto & e: ct){
                if( e.second >= 2 ) res += (e.second - 1)*e.second;
            }
            ct.clear();
        }
        return res;
    }
    int s_dist(pair<int,int> &p1, pair<int,int> &p2){
        int dx = p1.first - p2.first, dy = p1.second - p2.second;
        return dx*dx + dy*dy;
    }
};



int main(int argc, char const *argv[]){
    vector<pair<int,int> > pts = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
    Solution sol;
    Solution2 sol2;
    cout << sol.numberOfBoomerangs(pts) << endl;
    cout << sol2.numberOfBoomerangs(pts) << endl;
    return 0;
}
