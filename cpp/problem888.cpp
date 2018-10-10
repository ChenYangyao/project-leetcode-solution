
// Class: Use set to perform searching
// Description:
//  - You may also use unordered_set, but it is determined by size of the problem.
//  - Time cost: O(nA*log(nB)); Space cost: O(nB).
// Creat: Yangyao Chen, 2018/10/10

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int tot_A = accumulate( A.cbegin(), A.cend(), 0 ),
            tot_B = accumulate( B.cbegin(), B.cend(), 0 ),
            excg = (tot_A + tot_B)/2 - tot_A;
        set<int> set_B( B.cbegin(), B.cend() );
        for(auto i: A)
        if( set_B.find(i + excg) != set_B.end() )
            return vector<int>({i, i+excg});
    }
};
