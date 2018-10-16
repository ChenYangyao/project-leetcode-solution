class Solution {
public:
    int addDigits(int num) {
        while( num >= 10 ){
            num = getAdded(num);
        }
        return num;
    }
    int getAdded(int num){
        int added = 0;
        while(num){
            added += num%10;
            num /= 10;
        }
        return added;
    }
};
