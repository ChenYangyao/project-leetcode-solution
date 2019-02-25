/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
lever traverse
*/
import java.util.Queue;
import java.util.ArrayDeque;

class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        Queue<TreeNode> temp_node=new ArrayDeque<TreeNode>();
        temp_node.add(root);
        Queue<TreeNode> result;
        while(true){
            Queue<TreeNode> t_node=new ArrayDeque<TreeNode>();
            boolean tag=false;
            while(!temp_node.isEmpty()){
                TreeNode node=temp_node.peek();
                //System.out.print(node.val+";");
                if(node.left!=null){
                    node.left.val+=node.val;
                    t_node.add(node.left);
                    tag=true;
                }
                if(node.right!=null){
                    node.right.val+=node.val;
                    t_node.add(node.right);
                    tag=true;
                }
                if(node.left==null&&node.right==null){
                    t_node.add(node);
                }
                temp_node.poll();
            }
            //System.out.println();
            if(tag){
                temp_node=t_node;
            }else{
                //System.out.println("fuck");
                result=t_node;
                break;
            }
        }
        //System.out.println(result.peek().val);
        while(!result.isEmpty()){
            //System.out.println(result.peek().val);
            if(result.poll().val==sum){          
                return true;
            }
        }
        return false;
           
    }
}