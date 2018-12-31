#include <mystd.h>
using namespace std;

/**
 * solution with two stacks
 *
 * The ordered stack (ostk) is used to push element, while the reversed stack (rstk) 
 * is used to peek/pop element.
 * Once a peek/pop request comes, we transport elements from ostk to rstk, then do peek/pop.
 * Once a push request comes, we tranport elements back, then do push.
 *
 * Author: Yangyao, 2019/01/01. 
 * Happy new year and thanks for all the effort we have made in the past year.
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    /** Push element x to the back of queue. */
    
    void push(int x) {
        if( !rstk.empty() ){
            change_stk( rstk, ostk );
        }
        ostk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if( !ostk.empty() ){
            change_stk( ostk, rstk );
        }
        int temp = rstk.top();
        rstk.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if( !ostk.empty() ){
            change_stk( ostk, rstk );
        }
        return rstk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return ostk.empty() && rstk.empty();
    }
protected:
    typedef stack<int> stk_type;
    stk_type ostk, rstk;
    void change_stk( stk_type &src, stk_type &dest ){
        while( !src.empty() ){
            dest.push( src.top() );
            src.pop();
        }
    }
};



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
int main(int argc, char const *argv[]){
    MyQueue queue;

    // case from Leetcode problem
    queue.push(1);
    queue.push(2);  
    cout << queue.peek() << endl;  // returns 1
    cout << queue.pop() << endl;   // returns 1
    cout << queue.empty() << endl; // returns false
    return 0;
}