#include <mystd.h>
using namespace MYSTD;
using namespace std;

/**
 * determine the largest time by trying minute and seconds decendingly
 * e.g. for A = {2,3,0,6}: 
 * 1. Sort it to A = {6,3,2,0}.
 * 2. Find the largest tens-digit for hours, it is 2. If not found, return "".
 * 3. Find the largest units-digit for hours, it is 3 (not 6). If not found, 
 *      goes back to step 2 but search after the largest tens-digit ever found.
 * 4. combine remaining numbers, that is, 6 and 0, into a largest minutes, it 
 *      is 06. If not possible, goes back to step 2 but search after the largest 
 *      tens-digit ever found.
 *
 * Author: Yangyao, 2019/02/15
 */ 
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort( A.begin(), A.end(), greater<int>() );
        
        bool used[4] = {};
        int idx[4] = {};
        while( idx[0] < 4 && A[idx[0]] > 2 ) ++idx[0];
        while( idx[0] != 4 ){
            used[ idx[0] ] = true;
            fill_n(idx+1, 3, 0);
            if( A[idx[0]] == 2 ){
                while( idx[1] < 4 && ( used[idx[1]] || A[idx[1]] > 3 ) ) ++idx[1];
                if( idx[1] == 4 ){ used[idx[0]++]=false; continue; }
            }else{
                while( used[idx[1]] ) ++idx[1];
            }
            used[ idx[1] ] = true;
            while( used[ idx[2] ] ) ++idx[2];
            idx[3] = idx[2] + 1;
            while( used[ idx[3] ] ) ++idx[3];
            if( A[idx[2]] > 5 ) swap(idx[2], idx[3]);
            if( A[idx[2]] > 5 ){ used[idx[0]++] = used[idx[1]] = false; continue; }
            return toStr(A, idx);
        }
        return "";
    }
    string toStr(vector<int> &A, int *idx){
        string s = { '0' + A[idx[0]], '0' + A[idx[1]], ':', '0' + A[idx[2]], '0' + A[idx[3]] };
        return s;
    }
};

int main(int argc, char const *argv[]){
    Solution sol;

    // extreme case
    vector<int> A = {1,1,1,1};
    cout << sol.largestTimeFromDigits(A) << endl;
    
    // cases in Leetcode Problem
    A = {5,5,5,5};
    cout << sol.largestTimeFromDigits(A) << endl;

    A = {1,2,3,4};
    cout << sol.largestTimeFromDigits(A) << endl;
    return 0;
}