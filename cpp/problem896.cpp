class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        for(int i = 0; i < len - 1; ++i){
            if( A[i] < A[i+1] ){
                for( int j = i+1; j < len - 1; ++j ){
                    if( A[j] > A[j+1] ) return false;
                }
                break;
            }
            if( A[i] > A[i+1] ){
                for (int j = i+1; j < len - 1; ++j){
                    if( A[j] < A[j+1] ) return false;
                }
                break;
            }
        }
        return true;
    }
};
