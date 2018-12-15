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
    func findSecondMinimumValue(_ root: TreeNode?) -> Int {
        if (root == nil) {
            return -1
        }
        var stack = [TreeNode](); stack.append(root!)
        
        let smallest = root!.val
        var second_min = Int.max
        
        while !stack.isEmpty {
            let tmp = stack.removeLast()
            if (tmp.val > smallest && tmp.val < second_min) {
                second_min = tmp.val
            }
            if (tmp.left != nil) {
                stack.append(tmp.left!)
                stack.append(tmp.right!)
            }
        }
        
        return second_min == Int.max ? -1 : second_min
    }
}
