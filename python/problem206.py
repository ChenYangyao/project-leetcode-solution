class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        queue=[]
        node=head
        while node:
            queue.append(node.val)
            node=node.next
        node=head
        while queue:
            node.val=queue.pop()
            node=node.next
        return head
        