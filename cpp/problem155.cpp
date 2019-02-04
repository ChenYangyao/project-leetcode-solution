#include <mystd.h>
using namespace std;
using namespace MYSTD;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }

    struct HeapItem {
        int val;
        int stkId;
        HeapItem( int _val, int _stkId ): val(_val), stkId(_stkId) { }
    };

    vector<int> stk;
    vector<HeapItem> heap;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */