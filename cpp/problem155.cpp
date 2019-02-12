#include <mystd.h>
using namespace std;
using namespace MYSTD;
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


/**
 * I used to think that I must record the order of each pushed elements.
 * Here MinStack and MinStack2 implement this idea with insert-sort-like and
 * heap-like algorithm.
 * 
 * But after referring to Other Users' Solution, I find this could be better. 
 * What should I do is to record the minimum below each element in the stack. 
 * This is implemented by MinStack3.
 */

/**
 * MinStack - keep order of each pushed elements by a insert-sort-like method
 * Time for each op: O(n), Space: constant
 */ 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        _stk.emplace_back( x );
        _sorted.push_back(-1);
        int i = _sorted.size() - 2;
        while( i >= 0 && _stk[ _sorted[i] ].x < x  ){
            _sorted[i+1] = _sorted[i];
            _stk[ _sorted[i] ].id_sorted = i+1;
            --i;
        }
        _sorted[i+1] = _stk.size() - 1;
        _stk.back().id_sorted = i+1;
    }
    
    void pop() {
        int i = _stk.back().id_sorted;
        _stk.pop_back();
        while( i+1 < _sorted.size() ){
            _sorted[i] = _sorted[i+1];
            _stk[ _sorted[i+1] ].id_sorted = i;
            ++i;
        }
        _sorted.pop_back();
    }
    
    int top() {
        return _stk.back().x;
    }
    
    int getMin() {
        return _stk[ _sorted.back() ].x;
    }

    struct StkItem {
        int x;
        int id_sorted;
        StkItem( int _x, int _id_sorted = -1 ): x(_x), id_sorted(_id_sorted){ }
    };
    vector<StkItem> _stk;
    vector<int> _sorted;
};

/**
 * MinStack2 - keep order of each pushed elements by a heap
 * 
 * Time for each op: O(log(n)), Space: constant
 */ 
#define LCHILD(i) 2*i+1
#define RCHILD(i) 2*i+2
#define PARENT(i) (i-1)/2
class MinStack2 {
public:
    /** initialize your data structure here. */
    MinStack2() {}

    void push(int x) {
        _stk.emplace_back( x );
        _heap.push_back(-1);
        int i = _heap.size() - 1;
        while( i > 0 ){
            int p = PARENT(i);
            if( _stk[ _heap[p] ].x > x ){
                _heap[ i ] = _heap[ p ];
                _stk[ _heap[ p ] ].id_heap = i;
                i = p;
            }else{
                break;
            }
        }
        _heap[ i ] = _stk.size() - 1;
        _stk.back().id_heap = i;
    }
    
    void pop() {
        int i = _stk.back().id_heap; _stk.pop_back();
        int id_stk = _heap.back(); _heap.pop_back();
        
        int lc = LCHILD(i), k;
        while( lc < _heap.size() ){
            if( lc + 1 < _heap.size() ){
                k = _stk[ _heap[ lc ] ].x < _stk[ _heap[ lc + 1 ] ].x ? lc : (lc + 1);
            }else{
                k = lc;
            }
            k = _stk[ _heap[ k ] ].x < _stk[ id_stk ].x ? k : i;
            if( k != i ){
                _heap[ i ] = _heap[ k ];
                _stk[ _heap[k] ].id_heap = i;
                i = k;
                lc = LCHILD(i);
            }else break;
        }
        _heap[ i ] = id_stk;
        _stk[ id_stk ].id_heap = i;
    }
    
    int top() {
        return _stk.back().x;
    }
    
    int getMin() {
        return _stk[ _heap.front() ].x;
    }

    struct StkItem {
        int x;
        int id_heap;
        StkItem( int _x, int _id_heap = -1 ): x(_x), id_heap(_id_heap){ }
    };
    vector<StkItem> _stk;
    vector<int> _heap;
};

/**
 * MinStack3 - just record the mimimum in the stack below each element
 * 
 * Time for each op: constant, Space: constant
 * Reference: Leetcode User Solution
 */ 
class MinStack3 {
public:
    /** initialize your data structure here. */
    MinStack3() { }
    
    void push(int x) {
        _stk.push(x);
        _minStk.push( _minStk.empty()? x : min(x, _minStk.top())  );
    }
    
    void pop() {
        _stk.pop(); _minStk.pop();
    }
    
    int top() {
        return _stk.top();
    }
    
    int getMin() {
        return _minStk.top();
    }
    stack<int> _stk, _minStk;
};


template<typename T>
void test_mstk(){
    // case of Leetcode Problem
    {
        T mstk;
        mstk.push(-2);
        mstk.push(0);
        mstk.push(-3);
        cout << mstk.getMin() << endl;
        mstk.pop();
        cout << mstk.top() << endl;
        cout << mstk.getMin() << endl;
    }
    // case in Leetcode Judgement system
    {
        T mstk;
        mstk.push(2);
        mstk.push(0);
        mstk.push(3);
        mstk.push(0);
        cout << mstk.getMin() << endl; mstk.pop();
        cout << mstk.getMin() << endl; mstk.pop();
        cout << mstk.getMin() << endl; mstk.pop();
        cout << mstk.getMin() << endl;
    }
}


int main(int argc, char const *argv[]){

    test_mstk<MinStack>();
    test_mstk<MinStack2>();
    test_mstk<MinStack3>();
    
    return 0;
}
