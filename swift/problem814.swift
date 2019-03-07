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

//ref: https://leetcode.com/problems/binary-tree-pruning/solution/
class Solution {
    func pruneTree(_ root: TreeNode?) -> TreeNode? {
        _ = prune(root)
        return root
    }
    
    private func prune(_ node: TreeNode?) -> Bool {
        guard let node = node else {
            return true
        }
        if prune(node.left) {
            node.left = nil
        }
        if prune(node.right) {
            node.right = nil
        }
        return node.val == 0 && node.left == nil && node.right == nil
    }
}
