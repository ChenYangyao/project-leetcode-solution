class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        li = [root]
        dep = 0
        while li:
            dep += 1
            for i in range(len(li)):
                node = li.pop(0)
                
                if not node.left and not node.right:
                    return dep 
                if node.left:
                    li.append(node.left)
                if node.right:
                    li.append(node.right)
        
        return dep
        