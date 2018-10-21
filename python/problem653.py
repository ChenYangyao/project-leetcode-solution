class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        li=[]
        
        def tree(node,li):
            li.append(node.val)
            if node.left:
                tree(node.left,li)
            if node.right:
                tree(node.right,li)
        tree(root,li)
        setli=set(li)
        for i in setli:
            if k-i in setli and k-i!=i:
                return True
        return False
        