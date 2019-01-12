/**
 * Definition for a binary tree node.
 */
//Solution 1:recursive
import java.util.Stack;

import java.lang.Math;
class Solution {
    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }else{
            int h1=getHeight(root.left);
            int h2=getHeight(root.right);
            if(Math.abs(h1-h2)<=1){
                return isBalanced(root.left)&&isBalanced(root.right);
            }else{
                return false;
            }
        }
    }
    public int getHeight(TreeNode root){
        if(root==null){
            return 0;
        }else{
            int a=getHeight(root.left);
            int b=getHeight(root.right);
            if(a>=b){
                return a+1;
            }else{
                return b+1;
            }
        }
    }
}
//Solution2 Traverse tree with stack
class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x,TreeNode left,TreeNode right) { 
        this.left=left;
        this.right=right;
        this.val = x; 
    }
}

class Solution2{
   
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }else{
            Stack<TreeNode> node=new Stack<TreeNode>();
            TreeNode temp=root;
            while(temp!=null||!node.isEmpty()){
                while(temp!=null){
                    node.push(temp);
                    temp=temp.left;
                }
                if(!node.isEmpty()){
                    TreeNode condidate=node.pop();
                    if(Math.abs(getHeight(condidate.left)-getHeight(condidate.right))>1){
                        return false;
                    }
                    temp=condidate.right;
                }
            }
            return true;
        }
        
    }
    public int getHeight(TreeNode root){
        if(root==null){
            return 0;
        }else{
            Stack<TreeNode> node=new Stack<TreeNode>();
            Stack<Integer> height=new Stack<Integer>();
            //height.peek()>0--->left_child hasn't been visited
            //height.peek()<0--->left_child has been visited
            //height.peek()==0--->left_child and right_child have been visited
            int h=0;
            node.push(root);height.push(1);
            while(!node.isEmpty()){
                TreeNode temp=node.peek();
                int tag=height.peek();
                if(temp.left!=null){
                    if(tag>0){
                        node.push(temp.left);
                        height.pop();height.push(-1*tag);
                        height.push(tag+1);
                    }else if(tag<=0){
                        if(tag!=0&&temp.right!=null){
                            node.push(temp.right);
                            height.pop();height.push(0);
                            height.push(-1*tag+1);
                        }else{
                            node.pop();
                            height.pop();
                        }
                    }
                }else if(temp.right!=null){
                    if(tag==0){
                        node.pop();
                        height.pop();
                    }else{
                        node.push(temp.right);
                        height.pop();height.push(0);
                        height.push(tag+1);
                    }
                }else{
                    if(tag>h){
                        h=tag;
                    }
                    node.pop();
                    height.pop();
                }
            }
            return h;
        }
    }
}

public class problem110{
     public static void main(String args[]){
        TreeNode node_1=new TreeNode(1,null,null);
        TreeNode node_2=new TreeNode(2,null,null);
        TreeNode node_9=new TreeNode(9,node_1,node_2);
        TreeNode node_8=new TreeNode(8,null,null);
        TreeNode node_15=new TreeNode(15,node_8,null);
        TreeNode node_7=new TreeNode(7,null,null);
        TreeNode node_20=new TreeNode(20,node_15,node_7);
        TreeNode node_3=new TreeNode(3,node_9,node_20);
        Solution2 test=new Solution2();
        System.out.println(test.isBalanced(node_3));
    }
}
