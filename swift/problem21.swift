public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let ans = ListNode(0)
        var cur = ans; var p1 = l1; var p2 = l2
        
        while (p1 != nil && p2 != nil) {
            if (p1!.val < p2!.val) {
                cur.next = p1
                cur = p1!
                p1 = p1!.next
            } else {
                cur.next = p2
                cur = p2!
                p2 = p2!.next
            }
        }
        
        if (p1 != nil) {
            cur.next = p1
        } else if (p2 != nil) {
            cur.next = p2
        }
        
        return ans.next
    }
}
