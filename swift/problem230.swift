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
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        var counter = 0
        var stack = [TreeNode]()
        var tmp = root
        
        while true {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.left
            }
            tmp = stack.removeLast()
            counter += 1
            if (counter == k) {
                break
            }
            tmp = tmp!.right
        }
        
        return tmp!.val
    }
}
