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
//There are still some bug
class Solution {
    private static class input_info{
        static int last_val=Integer.MAX_VALUE-1;
        static int last_count=0;
        static int max_duplicate_num=0;
        static List<Integer> value_set=new ArrayList<Integer>();
    }

    //main methond
    public int[] findMode(TreeNode root){
        if(root==null){
            return null;
        }else{
            find_mode(root, node->implement_updtae_input_info(node));
        }
        if(input_info.value_set==null||input_info.value_set.isEmpty()){
            return null;
        }else{
            int[] result=new int[input_info.value_set.size()];
            for(int i=0;i<input_info.value_set.size();i++){
                result[i]=input_info.value_set.get(i);
            }
            return result;
        }  
    }
    public interface command{
        public void update_input_info(TreeNode node);
    }

    public static void implement_updtae_input_info(TreeNode node){
        if(node.val==input_info.last_val){
            input_info.last_count++;
        }else{
            input_info.last_val=node.val;
            input_info.last_count=1;
        }

        if(input_info.last_count>input_info.max_duplicate_num){
            input_info.value_set.clear();
            input_info.value_set.add(input_info.last_val);
            input_info.max_duplicate_num=input_info.last_count;
        }else if(input_info.last_count==input_info.max_duplicate_num){
            input_info.value_set.add(input_info.last_val);
        }
    }

    public void find_mode(TreeNode root,command com){
        if(root==null){
            return ;
        }else{
            find_mode(root.left,com);
            com.update_input_info(root);
            find_mode(root.right,com);
        }
    
    }
}