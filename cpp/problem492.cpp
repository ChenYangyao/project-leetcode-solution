class Solution {
public:
    vector<int> constructRectangle(int area) {
        int min = sqrt(area);
        while( area % min != 0 ){
            --min;
        }
        return {area/min, min};
    }
};
