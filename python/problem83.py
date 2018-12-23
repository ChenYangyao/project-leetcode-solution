class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return []
        node = head
        while node.next:
            if node.val != node.next.val:
                node = node.next
            else:
                node.next = node.next.next
        return head