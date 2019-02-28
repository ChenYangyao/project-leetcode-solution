class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        li = []
        while head:
            li.append(head.val)
            head = head.next
        
        l = 0
        r = len(li)-1
        while l<=r:
            if li[l] != li[r]:
                return False
            l += 1
            r -= 1
        return True
        
        
        
# O(1) space
# https://leetcode.com/problems/palindrome-linked-list/discuss/243254/super-clean-python-code
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast, slow, rev = head, head, None
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        while rev and rev.val == slow.val:
            rev, slow = rev.next, slow.next
        return not rev