#include "mystd.h"
using namespace std;


// Class: Use O(N^3) iteration
// Description:
//  - Time complexity: Theta(N^3), space complexity: constant
// Creat: Yangyao Chen, 2018/10/10
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        size_t npts = points.size();
        double lineeq[3];
        double maxarea = 0., temparea;
        for(size_t i = 0; i < npts; ++i){
            for (size_t j = i+1; j < npts; ++j){
                get_line_equation(points[i].data(), points[j].data(), lineeq);
                double maxdis = 0., tempdis;
                for(size_t k = j+1; k < npts; ++k){
                    tempdis = get_dis_point2line(lineeq, points[k].data());
                    if( tempdis > maxdis ) maxdis = tempdis;
                }
                temparea = 0.5*maxdis*get_dis( points[i].data(), points[j].data() );
                if( temparea > maxarea ) maxarea = temparea;
            }
        }
        return maxarea;
    }
    template<typename T>
    static void get_line_equation(const T *a, const T *b, double *lineeq){
        double diff[2];
        get_diff(a,b,diff);
        swap(diff[0],diff[1]);
        diff[0] = -diff[0];
        double norm = get_norm(diff);
        lineeq[0] = diff[0]/norm; lineeq[1] = diff[1]/norm;
        lineeq[2] = -(lineeq[0]*a[0]+lineeq[1]*a[1]);
    }
    template<typename T>
    static void get_diff(const T *a, const T *b, double *diff){
        diff[0] = a[0] - b[0];
        diff[1] = a[1] - b[1];
    }
    template<typename T>
    static double get_norm(const T *a){
        return sqrt(a[0]*a[0] + a[1]*a[1]);
    }
    template<typename T>
    static double get_dis(const T *a, const T *b){
        double diff[2];
        get_diff(a,b,diff);
        return get_norm(diff);
    }
    template<typename T>
    static double get_dis_point2line(const double *lineeq, const T *a){
        return abs( lineeq[0]*a[0] + lineeq[1]*a[1] + lineeq[2] );
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int> > points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    Solution sol;
    cout << sol.largestTriangleArea(points) << endl;
    return 0;
}
