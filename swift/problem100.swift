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
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        return (p == nil && q == nil) || (p?.val == q?.val) && isSameTree(p?.right, q?.right) && isSameTree(p?.left, q?.left)
        //if p == nil && q != nil, then p?.val == nil, and q?.val = q!.val, leading to false result of (p?.val == q?.val)
    }
}
