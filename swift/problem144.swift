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

//trivial pre-order traversal
class Solution {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
        var stack = [root]; var ans = [Int]()
        
        while !stack.isEmpty {
            let tmp = stack.removeLast()
            if (tmp.right != nil) {
                stack.append(tmp.right!)
            }
            if (tmp.left != nil) {
                stack.append(tmp.left!)
            }
            ans.append(tmp.val)
        }
        
        return ans
    }
}
