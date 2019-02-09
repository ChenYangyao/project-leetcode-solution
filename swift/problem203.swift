public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        var prev = head
        
        while (prev?.val == val) {
            prev = prev!.next
        }
        
        let head = prev
        var cur = prev?.next
        
        while (cur != nil) {
            if (cur!.val == val) {
                prev!.next = cur!.next
                cur = cur!.next
            } else {
                prev = cur!
                cur = cur!.next
            }
        }
        
        return head
    }
}
