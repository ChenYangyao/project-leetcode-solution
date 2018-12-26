public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        var record = Int.min
        let ans = head; var cur = head; var prev = head
        
        while (cur != nil) {
            if (cur!.val == record) {
                prev!.next = cur!.next
                cur = cur!.next
            } else {
                record = cur!.val
                prev = cur
            }
        }
        
        return ans
    }
}
