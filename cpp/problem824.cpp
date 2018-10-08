class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        size_t i = 0, j = S.find(' '), count = 0;
        while(true){
            res += _toGoatLatin( S.substr(i,j-i), ++count );
            if( j == S.npos ) break;
            res += " ";
            i = j+1;
            j = S.find( ' ', i );
        }
        return res;
    }
    string _toGoatLatin(const string &S, size_t i){
        switch(tolower(S[0])){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return S + "ma" + string( i, 'a' );
            default:
                return string( S.begin()+1, S.end() ) + S[0] + "ma" + string(i,'a');
        }
    }

};
