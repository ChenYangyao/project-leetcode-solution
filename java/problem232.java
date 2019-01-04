import java.util.*;
class MyQueue {
    private Stack<Integer> positiveStack;
    private Stack<Integer> negativeStack;
    private boolean tag;
    /** Initialize your data structure here. */
    public MyQueue() {
        positiveStack=new Stack<Integer>();
        negativeStack=new Stack<Integer>();
        tag=true;//represent positiveStack,tag=false represent negativeStack
    }
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(tag){
            while(!positiveStack.empty()){
                negativeStack.push(positiveStack.pop());
            }
            negativeStack.push(x);
            tag=false;
        }else{
            negativeStack.push(x);
        }   
    }
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(tag){
            return positiveStack.pop();
        }else{
            while(!negativeStack.empty()){
                positiveStack.push(negativeStack.pop());
            }
            tag=true;
            return positiveStack.pop();
        }
        
    }  
    /** Get the front element. */
    public int peek() {
        if(tag){
            return positiveStack.peek();
        }else{
            while(!negativeStack.empty()){
                positiveStack.push(negativeStack.pop());
            }
            tag=true;
            return positiveStack.peek();        
        }
        
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(positiveStack.empty()&&negativeStack.empty()){
            return true;
        }else{
            return false;
        }
    }
}