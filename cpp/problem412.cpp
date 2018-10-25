class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        char temps[128];
        for (int i = 1; i <= n; ++i){
            if( i % 3 == 0 ){
                if( i % 5 == 0 ) sprintf(temps, "FizzBuzz");
                else sprintf(temps, "Fizz");
            }else if( i % 5 == 0 ){
                sprintf(temps,"Buzz");
            }else{
                sprintf(temps,"%d",i);
            }
            res.emplace_back( temps );
        }
        return res;
    }
};
