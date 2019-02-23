import java.util.*;
class MyStack {
    private static boolean tag;
    private Queue<Integer> queue_1;
    private Queue<Integer> queue_2;
    /** Initialize your data structure here. */
    public MyStack() {
        tag=true;
        //elements in queue_1 tag==true;elements in queue_2 tag=flase;
        queue_1=new ArrayDeque<Integer>();
        queue_2=new ArrayDeque<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x){
        if(tag){
            queue_2.add(x);
            while(!queue_1.isEmpty()){
                queue_2.add(queue_1.remove());
            }
        }else{
            queue_1.add(x);
            while(!queue_2.isEmpty()){
                queue_1.add(queue_2.remove());
            }
        }
        tag=!tag;
    }
  
    /** Removes the element on top of the stack and returns that element. */
    public int pop(){
        if(tag){
            return queue_1.remove();
        }else{
            return queue_2.remove();
        }
   
    }
    
    /** Get the top element. */
    public int top() {
        if(tag){
            return queue_1.peek();
        }else{
            return queue_2.peek();
        }
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty(){
        return queue_1.isEmpty()&&queue_2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */