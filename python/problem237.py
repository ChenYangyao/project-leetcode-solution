



class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        while node.next:            
            if not node.next.next:
                node.val=node.next.val
                node.next=None
                break
            node.val=node.next.val
            node=node.next

                
