// Class: Parentheses mathing is a classical problem, which is typically implemeted with a stack (see textbooks for data structure).
//      Here the only charaters in 'S' are parentheses, so we repalce the stack with a counter 'nLeft'.
// Creat: Yangyao Chen, 2018/10/26
class Solution {
public:
    int minAddToMakeValid(string S) {
        int nLeft = 0, err = 0;
        for(auto c: S){
            if( c == '(' ) ++nLeft;
            else{
                if( nLeft ) --nLeft;
                else ++err;
            }
        }
        return err + nLeft;
    }
};
