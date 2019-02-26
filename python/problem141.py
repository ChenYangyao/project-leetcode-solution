class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
            
        while head:
            if not head.val :
                return True
            head.val = None
            head = head.next
        return False
        