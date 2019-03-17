public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    func flipEquiv(_ root1: TreeNode?, _ root2: TreeNode?) -> Bool {
        guard let root1 = root1 else { return root2 == nil }
        guard let root2 = root2 else { return false}
        
        if (root1.val != root2.val) {
            return false
        }
        
        let l1 = root1.left; let r1 = root1.right
        let l2 = root2.left; let r2 = root2.right
        
        if (l1?.val == r1?.val) {
            return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2))
        } else if (l1?.val == l2?.val && r1?.val == r2?.val) {
            return flipEquiv(l1, l2) && flipEquiv(r1, r2)
        } else if (l1?.val == r2?.val && r1?.val == l2?.val) {
            return flipEquiv(l1, r2) && flipEquiv(r1, l2)
        }
        
        return false
    }
}
