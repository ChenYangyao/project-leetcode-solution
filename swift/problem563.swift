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

//ref: https://leetcode.com/problems/binary-tree-tilt/solution/
class Solution {
    private var tilt = 0
    
    func findTilt(_ root: TreeNode?) -> Int {
        diff(root)
        defer {
            tilt = 0
        }
        return tilt
    }
    
    @discardableResult
    private func diff(_ root: TreeNode?) -> Int {
        if (root == nil) {
            return 0
        }
        let left_tilt = diff(root!.left)
        let right_tilt = diff(root!.right)
        tilt += abs(left_tilt - right_tilt)
        return left_tilt + right_tilt + root!.val
    }
}
