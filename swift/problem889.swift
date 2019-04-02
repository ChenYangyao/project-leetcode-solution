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

//ref: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)
class Solution {
    func constructFromPrePost(_ pre: [Int], _ post: [Int]) -> TreeNode? {
        var stack = [TreeNode]()
        stack.append(TreeNode(pre[0]))
        
        var j = 0
        
        for i in 1..<pre.count {
            let node = TreeNode(pre[i])
            while (stack.last!.val == post[j]) {
                stack.removeLast(1)
                j += 1
            }
            if (stack.last!.left == nil) {
                stack.last!.left = node
            } else {
                stack.last!.right = node
            }
            stack.append(node)
        }
        
        return stack[0]
    }
}
