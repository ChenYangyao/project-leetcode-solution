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

//insert is trivial
//solution keeping the tree balanced will be added later
class Solution {
    func insertIntoBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        if (root == nil) {
            return TreeNode(val)
        }
        
        var cur = root
        
        while (cur != nil) {
            if (cur!.val > val) {
                if (cur!.left == nil) {
                    cur!.left = TreeNode(val)
                    break
                }
                cur = cur!.left
            } else {
                if (cur!.right == nil) {
                    cur!.right = TreeNode(val)
                    break
                }
                cur = cur!.right
            }
        }
        
        return root
    }
}
