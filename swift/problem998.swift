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
    func insertIntoMaxTree(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        let fake: TreeNode? = TreeNode(0)
        fake!.right = root
        
        var p = root; var prev = fake
        
        while (p != nil && p!.val > val) {
            prev = p
            p = p!.right
        }
        
        let ins = TreeNode(val)
        ins.left = p
        prev!.right = ins
        
        return fake!.right
    }
}
