#include "mystd.h"
using namespace std;

/**
 * like an ordinary post-order traversal of tree
 * Here I implement it recursively.
 */
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        bits.assign(num, 0);
        readBinaryWatch( num, 10 );
        return res;
    }
    /**
     * lighten 'rem_num' bits into last 'led_id' bits of the watch.
     */
    void readBinaryWatch(int rem_num, int led_id) {
        if( rem_num == 0 ){
            get_time(); return;
        }
        for (int i = led_id; i >= rem_num; --i){
            bits[ rem_num - 1 ] = i;
            readBinaryWatch(rem_num - 1, i - 1);
        }
    }
    /**
     * convert lightening 'bits' into a string
     * Note that hour == 12 is not allowed, nor is minutes = 60.
     * The hour should begin with non-zero char, while minuts must have 2 digits.
     */
    void get_time(){
        int min = 0, hr = 0;
        for(int bit: bits){
            if( bit >= 7 ) hr += 1 << (bit - 7);
            else min += 1 << (bit - 1);
        }
        if( min < 60 && hr < 12 ){
            sprintf(temps, "%d:%02d", hr, min);
            res.emplace_back(temps);
        }
    }
protected:
    vector<string> res;
    vector<int> bits;
    char temps[8];
};

/**
 * the same idea can be implemented with a stack,
 * without recursion.
 */
class Solution2 {
public:
    vector<string> readBinaryWatch(int num) {
        bits.assign( num, 0 );

        stack<stkitem> stk;
        stk.emplace( num, 11 );
        while( !stk.empty() ){
            auto &top = stk.top();
            if( top.rem_num == 0 ) get_time();
            else if( top.taken > top.rem_num ){
                bits[ top.rem_num - 1 ] = --top.taken;
                stk.emplace( top.rem_num - 1, top.taken );
                continue;
            }
            stk.pop();
        }
        return res;
    }
    void get_time(){
        int min = 0, hr = 0;
        for(int bit: bits){
            if( bit >= 7 ) hr += 1 << (bit - 7);
            else min += 1 << (bit - 1);
        }
        if( min < 60 && hr < 12 ){
            sprintf(temps, "%d:%02d", hr, min);
            res.emplace_back(temps);
        }
    }
protected:
    vector<string> res;
    vector<int> bits;
    char temps[8];
    struct stkitem{
        int rem_num;
        int taken;
        stkitem(int _rem_num, int _taken):
            rem_num(_rem_num), taken(_taken){}
    };
};


int main(int argc, char const *argv[]){
    // here is the example from Leetcode question, lightening 1 bits.
    {
        Solution sol;
        auto res = sol.readBinaryWatch(1);
        for(auto & i: res){
            cout << i << " ";
        }
        cout << endl;
    }{
        Solution2 sol2;
        auto res = sol2.readBinaryWatch(1);
        for(auto & i: res){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
