class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for( const string & op: ops ){
            if( op[0] == 'D' ){
                res.push_back( res.back() * 2 );
            }else if( op[0] == 'C' ){
                res.pop_back();
            }else if( op[0] == '+' ){
                res.push_back( res.back() + res[ res.size() - 2 ] );
            }else{
                res.push_back( stoi( op ) );
            }
        }
        return accumulate( res.begin(), res.end(), 0 );
    }
};
