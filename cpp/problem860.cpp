class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0, n10 = 0;
        for(const auto i: bills){
            if( i == 5 ) ++n5;
            else if( i == 10 ){
                if( n5 ){ --n5; ++n10; }
                else return false;
            }else{
                if( n5 && n10 ){ --n5; --n10; }
                else if( n5 > 2 ) n5 -= 3;
                else return false;
            }
        }
        return true;
    }
};
