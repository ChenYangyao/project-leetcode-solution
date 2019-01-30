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
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        if (root == nil) {
            return false
        }
        if (root!.left == nil && root!.right == nil) {
            return sum == root!.val
        }
        return hasPathSum(root!.left,sum - root!.val) || hasPathSum(root!.right,sum - root!.val)
    }
}
