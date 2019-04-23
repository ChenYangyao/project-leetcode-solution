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

//ref: https://leetcode.com/problems/diameter-of-binary-tree/solution/
class Solution {
    private var ans = 0
    
    @discardableResult
    private func height(_ root: TreeNode?) -> Int {
        if (root == nil) {
            return 0
        }
        let left_dp = height(root!.left)
        let right_dp = height(root!.right)
        ans = max(ans,left_dp+right_dp)
        return max(left_dp,right_dp)+1
    }
    
    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        height(root)
        defer {
            ans = 0
        }
        return ans
    }
}
