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

//trivial in-order traversal
class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var stack = [TreeNode](); var tmp = root; var ans = [Int]()
        
        while (!stack.isEmpty || tmp != nil) {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.left
            }
            tmp = stack.removeLast()
            ans.append(tmp!.val)
            tmp = tmp!.right
        }
        
        return ans
    }
}
