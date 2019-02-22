#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * just simulate the walk
 * The obstacles are converted to a hash-set for fast looking-up.
 */ 
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        std::unordered_set<long> st;
        for(const auto &i: obstacles) st.emplace( long(i[0])*100000 + i[1] );

        int dx = 0, dy = 1, x = 0, y = 0, maxdis = 0;
        for(const auto &command: commands){
            switch(command){
                case -2: swap(dx,dy); dx = -dx; break;
                case -1: swap(dx,dy); dy = -dy; break;
                default:
                    maxdis = max(maxdis, x*x+y*y);
                    for(int i=0; i<command; ++i){
                        if( st.find( long(x+dx)*100000+y+dy ) == st.end() ){
                            x += dx; y += dy;       
                        }else break;
                    }
            }
        }
        maxdis = max(maxdis, x*x+y*y);
        return maxdis;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // cases in Leetcode Problem
    vector<int> commands = {4,-1,3};
    vector<vector<int> > obst;
    cout << sol.robotSim( commands, obst ) << endl;

    commands.assign({4,-1,4,-2,4});
    obst.assign({{2,4}});
    cout << sol.robotSim( commands, obst ) << endl;

    return 0;
}

