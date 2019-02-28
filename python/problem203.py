class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        cur,fast = None,head
        while fast:
            if fast.val == val:
                if not cur:
                    fast,head = fast.next,fast.next
                else:
                    cur.next = fast.next
                    fast = fast.next
            else:
                cur = fast
                fast = fast.next
        return head
            

            
# https://leetcode.com/problems/remove-linked-list-elements/discuss/239179/Simple-Python-Solution-(No-Dummy-Variables)
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        rem, rem_tail = None, None
        while head:
            if head.val != val:
                temp = ListNode(head.val)
                if rem:  # not empty
                    rem_tail.next, rem_tail = temp, temp 
                else:
                    rem, rem_tail = temp, temp
            head = head.next
        return rem