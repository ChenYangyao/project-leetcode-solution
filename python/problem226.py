import time

''' 二叉树创建和遍历实现'''
class Node:
    def __init__(self,item):
        self.item = item
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def add(self, item):
        node = Node(item)
        if self.root is None:
            self.root = node
        else:
            q = [self.root]

            while True:
                pop_node = q.pop(0)
                if pop_node.left is None:
                    pop_node.left = node
                    return
                elif pop_node.right is None:
                    pop_node.right = node
                    return
                else:
                    q.append(pop_node.left)
                    q.append(pop_node.right)

    def traverse(self):  # 层次遍历
        if self.root is None:
            return None
        q = [self.root]
        res = [self.root.item]
        while q != []:
            pop_node = q.pop(0)
            if pop_node.left is not None:
                q.append(pop_node.left)
                res.append(pop_node.left.item)

            if pop_node.right is not None:
                q.append(pop_node.right)
                res.append(pop_node.right.item)
        return res

    def preorder(self,root):  # 先序遍历
        if root is None:
            return []
        result = [root.item]
        left_item = self.preorder(root.left)
        right_item = self.preorder(root.right)
        return result + left_item + right_item

    def inorder(self,root):  # 中序遍历
        if root is None:
            return []
        result = [root.item]
        left_item = self.inorder(root.left)
        right_item = self.inorder(root.right)
        return left_item + result + right_item

    def postorder(self,root):  # 后序遍历
        if root is None:
            return []
        result = [root.item]
        left_item = self.postorder(root.left)
        right_item = self.postorder(root.right)
        return left_item + right_item + result
        
        '''二叉树结束'''
      
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.invert(root)
        return root
        
    def invert(self,node):
        if node and (node.right or node.left):
            node.left,node.right=node.right,node.left
            self.invert(node.right)
            self.invert(node.left)
            
    #from discuss       
    def invertTree2(self, root):
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                node.left, node.right = node.right, node.left
                stack += node.left, node.right
        return root
            
            
if __name__ == '__main__':
    t = Tree() 
    
    for i in range(8000):
        t.add(i)
    #time test for invertTree
    t1=time.time()
    c=Solution()
    c.invertTree(t.root)
    t2=time.time()
    print('时间为',t2-t1)
    
    #time test for invertTree2
    t3=time.time()
    c.invertTree2(t.root)
    t4=time.time()
    print('时间为',t4-t3)