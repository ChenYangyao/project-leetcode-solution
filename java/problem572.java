
import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        Stack<TreeNode> s_stack=new Stack<TreeNode>();
        if(s==null){
            if(t==null){
                return true;
            }else{
                return false;
            }
        }else{
            if(t==null){
                return false;
            }
        }
        s_stack.push(s);
        while(!s_stack.empty()){
            TreeNode temp=s_stack.pop();
            //System.out.println(temp.val);
            if(isSame(temp, t)){
                return true;
            }else{
                //System.out.println(temp.val);
                if(temp.left!=null){
                    s_stack.push(temp.left);
                }
                if(temp.right!=null){
                    s_stack.push(temp.right);
                }
            }
        }
        return false;
    }

    public boolean isSame(TreeNode s,TreeNode t){
        if(s.val!=t.val){
            return false;
        }
        Stack<TreeNode> s_stack=new Stack<TreeNode>();
        Stack<TreeNode> t_stack=new Stack<TreeNode>();
        s_stack.push(s);t_stack.push(t);
        while((!s_stack.empty())){
            TreeNode s_temp=s_stack.pop();
            TreeNode t_temp=t_stack.pop();
            boolean same_no_null_Left=false;
            boolean same_no_null_Right=false;
            if(s_temp.left==null){
                if(t_temp.left!=null){
                    return false;
                }
            }else{
                if(t_temp.left!=null){
                    if(t_temp.left.val==s_temp.left.val){
                        same_no_null_Left=true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }

            if(s_temp.right==null){
                if(t_temp.right!=null){
                    return false;
                }
            }else{
                if(t_temp.right!=null){
                    if(t_temp.right.val==s_temp.right.val){
                        same_no_null_Right=true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
            if(same_no_null_Left){
                s_stack.push(s_temp.left);
                t_stack.push(t_temp.left);
            }
            if(same_no_null_Right){
                s_stack.push(s_temp.right);
                t_stack.push(t_temp.right);
            }
        }
        return true;
    }
    
}