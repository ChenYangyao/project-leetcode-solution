#include <mystd.h>
using namespace MYSTD;
using namespace std;
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


/**
 * method slow at pop() but quick at push()
 * push the element directly into the queue.
 * pop the element by moving the queue into another.
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        if( sq1.empty() ) sq2.push( x );
        else sq1.push( x );
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() { return sq1.empty() ? moveExceptLast( sq2, sq1 ) : moveExceptLast( sq1, sq2 ); }
    
    /** Get the top element. */
    int top() { return sq1.empty() ? moveAll( sq2, sq1 ) : moveAll( sq1, sq2 ); }
    
    /** Returns whether the stack is empty. */
    bool empty() { return sq1.empty() && sq2.empty(); }
protected:
    typedef queue<int> sq_type;
    sq_type sq1, sq2;    // two single-ended queue
    
    int moveExceptLast( sq_type &sq1, sq_type &sq2  ){
        int x = sq1.front(); sq1.pop();
        while( !sq1.empty() ){
            sq2.push( x );
            x = sq1.front(); sq1.pop();
        }
        return x;
    }
    int moveAll( sq_type &sq1, sq_type &sq2 ){
        int x = moveExceptLast( sq1, sq2 );
        sq2.push(x);
        return x;
    }
};

/**
 * method slow at push() but quick at pop()
 * push the element into a empty queue followed by moving the existing queue into the empty.
 * pop the element directly fron the existing queue.
 */
class MyStack2 {
public:
    /** Initialize your data structure here. */
    MyStack2() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        if( sq1.empty() ) push( sq2, sq1, x );
        else push( sq1, sq2, x );
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;
        if( sq1.empty() ){ x = sq2.front(); sq2.pop(); }
        else{ x = sq1.front(); sq1.pop(); }
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return sq1.empty() ? sq2.front() : sq1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() { return sq1.empty() && sq2.empty(); }
protected:
    typedef queue<int> sq_type;
    sq_type sq1, sq2;    // two single-ended queue
    
    void push( sq_type &sq1, sq_type &sq2, int x ){
        sq2.push( x );
        while( !sq1.empty() ){
            sq2.push( sq1.front() ); sq1.pop();
        }
    }
};


int main(int argc, char const *argv[]){
    MyStack mstk;
    MyStack2 mstk2;

    mstk.push(1);
    mstk.push(2);
    cout << mstk.top() << endl;
    cout << mstk.pop() << endl;
    cout << mstk.empty() << endl << endl;

    mstk2.push(1);
    mstk2.push(2);
    cout << mstk2.top() << endl;
    cout << mstk2.pop() << endl;
    cout << mstk2.empty() << endl;
    return 0;
}