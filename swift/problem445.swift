public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

//ref: https://leetcode.com/problems/add-two-numbers-ii/discuss/323570/Java-Solution-with-O(n)-time-and-O(1)-space
//time complexity Θ(N)
class Solution {
    private func getLength(_ node: ListNode?) -> Int {
        var cur = node; var length = 0
        
        while (cur != nil) {
            length += 1
            cur = cur!.next
        }
        
        return length
    }
    
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var length1 = getLength(l1)
        var length2 = getLength(l2)
        
        var p1 = l1; var p2 = l2
        
        if (length1 < length2) {
            swap(&p1, &p2)
            swap(&length1, &length2)
        }
        
        var start = length1 - length2
        let ans = ListNode(0); var cur = ans
        var potentCarry: ListNode?
        var potentCarryPrev = cur
        
        while (start > 0) {
            cur.next = ListNode(p1!.val)
            p1 = p1!.next
            cur = cur.next!
            start -= 1
            
            if (cur.val == 9) {
                if (potentCarry == nil) {
                    potentCarry = cur
                }
            } else {
                potentCarry = nil
                potentCarryPrev = cur
            }
        }
        
        while (p1 != nil) {
            let (sum, carry) = {(_ summation: Int) -> (Int, Bool) in
                return (summation%10, summation >= 10)
            }(p1!.val + p2!.val)
            
            p1 = p1!.next; p2 = p2!.next
            cur.next = ListNode(sum); cur = cur.next!
            
            if (sum == 9) {
                if (potentCarry == nil) {
                    potentCarry = cur
                }
            } else {
                if carry {
                    if (potentCarry != nil) {
                        while (potentCarry !== cur) {
                            potentCarry!.val = 0
                            potentCarry = potentCarry!.next
                        }
                    }
                    potentCarryPrev.val += 1
                }
                potentCarry = nil
                potentCarryPrev = cur
            }
        }
        
        return ans.val == 0 ? ans.next : ans
    }
}
