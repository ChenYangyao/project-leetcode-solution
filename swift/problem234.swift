public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func isPalindrome(_ head: ListNode?) -> Bool {
        if (head?.next == nil) {
            return true
        }
        
        var ans = true
        var slow = head; var fast = head
        
        var length = 0
        while (fast != nil) {
            fast = fast!.next
            length += 1
        }
        
        length /= 2
        var counter = length
        
        while (length != 0) {
            slow = slow!.next
            length -= 1
        }
        
        var prev: ListNode? = nil; var holder = head
        
        while (slow != nil) {
            let tmp = slow!.next
            slow!.next = prev
            prev = slow
            slow = tmp
        }
        
        //record the head of reversed linked list
        slow = prev
        
        while (counter != 0) {
            if (prev!.val != holder!.val) {
                ans = false
                break
            }
            holder = holder!.next
            prev = prev!.next
            counter -= 1
        }
        
        //recover original sequence
        prev = nil
        while (slow != nil) {
            let tmp = slow!.next
            slow!.next = prev
            prev = slow
            slow = tmp
        }
        
        return ans
    }
}
