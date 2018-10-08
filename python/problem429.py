"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        li=[]
        depth=-1
        if not root:
            return li  
        queue=[root] 
        while queue:
            lq=len(queue)
            depth+=1
            li.append([])
            while lq>0:
                node=queue.pop(0)
                lq-=1
                li[depth].append(node.val)
                for i in node.children:
                    queue.append(i)
        return li