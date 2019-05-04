public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

//this problem should be simple not medium
class Solution {
    func numComponents(_ head: ListNode?, _ G: [Int]) -> Int {
        let G = Set(G); var ans = 0
        
        var cur = head
        while (cur != nil) {
            if (G.contains(cur!.val) && (cur!.next == nil || !G.contains(cur!.next!.val))) {
                ans += 1
            }
            cur = cur!.next
        }
        
        return ans
    }
}
