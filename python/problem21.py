# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result=l=ListNode(0)  #2 listnode
        while l1 and l2:
            if l1.val<l2.val:
                l.next=l1
                l1=l1.next
                
            else:
                l.next=l2
                l2=l2.next
            l=l.next
        l.next=l1 or l2  
        return result.next
        