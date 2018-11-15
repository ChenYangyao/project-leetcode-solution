class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n_satisfied = 0;
        int ig = 0, is = 0, ng = g.size(), ns = s.size();
        while( ig < ng && is < ns ){
            while( g[ig] > s[is] && is < ns ) ++is;
            if( is < ns ){ ++is; ++ig; ++n_satisfied; }
        }
        return n_satisfied;
    }
};
