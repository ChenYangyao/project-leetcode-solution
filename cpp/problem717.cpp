// Class: Solution by counting number of '1's before the last zero.
// Creat: Yangyao Chen, 2018/10/22
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int numOnes= 0;
        for (int i = n-2; i >= 0; --i){
            if( bits[i] == 1 ) ++numOnes;
            else break;
        }
        return (numOnes % 2)?false:true;
    }
};
