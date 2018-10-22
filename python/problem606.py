''' wrong
class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        def tree(node,s):
            s+=str(node.val)
            if node.left:
                s+='('+str(node.left.val)+tree(node.left,s)+')'
                
            else:
                s+='('+')'
            if node.right:
                s+='('+str(node.right.val)+tree(node.right,s)+')'
                
            return s
        s=''
        return tree(t,s)
'''

# from solution
class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ""
        if not (t.left or t.right):
            return str(t.val)+''
        if not t.right:
            return str(t.val)+"("+self.tree2str(t.left)+")";
        return str(t.val)+"("+self.tree2str(t.left)+")("+self.tree2str(t.right)+")"        