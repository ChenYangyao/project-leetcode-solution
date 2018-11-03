//totally the same as problem530
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
    func minDiffInBST(_ root: TreeNode?) -> Int {
        var stack = [TreeNode]()
        var tmp = root
        var prev = 0
        var result = Int.max
        var flag = true
        
        while (stack.count > 0 || tmp != nil) {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.left
            }
            tmp = stack.removeLast()
            if flag {
                flag = false
                prev = tmp!.val
                tmp = tmp!.right
                continue
            } else {
                result = min(result, tmp!.val - prev)
                prev = tmp!.val
                tmp = tmp!.right
            }
        }
        return result
    }
}
