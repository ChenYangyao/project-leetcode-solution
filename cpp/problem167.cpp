class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1, temp;
        while( (temp = numbers[i] + numbers[j]) != target ){
            if( temp > target ) --j;
            else ++i;
        }
        return {i+1,j+1};
    }
};
