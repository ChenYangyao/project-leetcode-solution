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
    func sumOfLeftLeaves(_ root: TreeNode?) -> Int {
        var tmp = root
        var stack = [TreeNode]()
        var sum = 0
        var flag = false
        
        while (stack.count > 0 || tmp != nil) {
            flag = false
            if (tmp?.left != nil) {
                flag = true
            }
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.left
            }
            tmp = stack.removeLast()
            if (flag && tmp!.right == nil) {
                sum += tmp!.val
            }
            tmp = tmp!.right
        }
        
        return sum
    }
}
